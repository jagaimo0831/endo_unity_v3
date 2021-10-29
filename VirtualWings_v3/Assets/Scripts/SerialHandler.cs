using UnityEngine;
using System.Collections;
using System.IO.Ports;
using System.Threading;

public class SerialHandler : MonoBehaviour
{
	public delegate void SerialDataReceivedEventHandler(string message); //delegate...関数を入れられる変数. 
	public event SerialDataReceivedEventHandler OnDataReceived; //delagateと似ている．外部から事項と代入ができない．

	[SerializeField] public string portName = "COM3"; // ポート名(Macだと/dev/tty.usbmodem1421など)
	public int baudRate    = 115200;  // ボーレート[bps](Arduinoに記述したものに合わせる)

	private SerialPort serialPort_; //SerialPortクラス(https://docs.microsoft.com/ja-jp/dotnet/api/system.io.ports.serialport?view=dotnet-plat-ext-5.0)...シリアルポートリソースを表す
	private Thread thread_; //Threadクラス(https://docs.microsoft.com/ja-jp/dotnet/api/system.threading.thread?view=net-5.0)...スレッドを作成および制御し，その優先順位の設定およびステータスの取得を実行
	private bool isRunning_ = false; //bool型

	private string message_;
	private bool isNewMessageReceived_ = false;

	void Awake()
	{
		Open();
	}

	void Update()
	{
		if (isNewMessageReceived_) {
			OnDataReceived(message_);
		}
		isNewMessageReceived_ = false;
	}

	void OnDestroy() //ゲームオブジェクトが削除された時に実行されるメソッド
	{
		Close();
	}

	private void Open()
	{
		serialPort_ = new SerialPort(portName, baudRate, Parity.None, 8, StopBits.One);
		//または
		//serialPort_ = new SerialPort(portName, baudRate);
		serialPort_.Open();

		isRunning_ = true;

		thread_ = new Thread(Read);
		thread_.Start();
	}

	private void Close()
	{
		isNewMessageReceived_ = false;
		isRunning_ = false;

		if (thread_ != null && thread_.IsAlive) {
			thread_.Join();
		}

		if (serialPort_ != null && serialPort_.IsOpen) {
			serialPort_.Close();
			serialPort_.Dispose();
		}
	}

	private void Read()
	{
		while (isRunning_ && serialPort_ != null && serialPort_.IsOpen) {
			try {
				message_ = serialPort_.ReadLine();
				isNewMessageReceived_ = true;
			} catch (System.Exception e) {
				Debug.LogWarning(e.Message);
			}
		}
	}

	public void Write(string message)
	{
		try {
			serialPort_.Write(message);
		} catch (System.Exception e) {
			Debug.LogWarning(e.Message);
		}
	}
}