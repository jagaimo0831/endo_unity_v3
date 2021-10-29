using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SerialSend_forHapticsDev : MonoBehaviour
{
    //SerialHandler.csのクラス
    public SerialHandler serialHandler_Send;
	public SerialHandler serialHandler_Receive;

   	//public Text text;
    int i = 0;

	[SerializeField] private int threshold = 600;


	void Start () {
		//信号を受信したときに、そのメッセージの処理を行う
		serialHandler_Receive.OnDataReceived += OnDataReceived;
	}
	
	void Update () {
		
	}

    /*
    void FixedUpdate() //ゲーム内時間の一定間隔で呼び出される //ここは0.001秒ごとに実行される 
    {
        i = i + 1; //iを加算していって1秒ごとに"1"のシリアル送信を実行
        if(i > 999)
        {
            serialHandler.Write("1");
            i = 0;
        }
    }
    */

    //シリアルを受け取った時の処理
	void OnDataReceived(string message) {
		try {
			int message2 = int.Parse(message);

			if(message2 > threshold){
				serialHandler_Send.Write("1");
			} 
		} catch (System.Exception e) {
			Debug.LogWarning(e.Message);
		}
	}
}