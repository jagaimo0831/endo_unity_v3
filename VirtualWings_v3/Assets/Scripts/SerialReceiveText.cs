// シリアル通信のテストスクリプト：Arduinoからのテキスト(Serial.println())を表示する


using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SerialReceiveText : MonoBehaviour {

	public SerialHandler serialHandler;
	public Text text;

	//シリアルを受け取った時の処理
	void OnDataReceived(string message) {
		try {
			text.text = message; // シリアルの値をテキストに表示
			Debug.Log(message);	// コンソールに表示				
		} catch (System.Exception e) {
			Debug.LogWarning(e.Message);
		}
	}

	/*
	//シリアルを受け取った時の処理(閾値によって挙動が変わるver.)
	[SerializeField] private int threshold = 600;
	void OnDataReceived2(string message) {
		try {
			int message2 = int.Parse(message);	// message2は送られた文字列を数に変換し，比較が出来るようにするため
			Debug.Log(message);

			if(message2 > threshold){
				text.text = message; // シリアルの値をテキストに表示
			}			
		} catch (System.Exception e) {
			Debug.LogWarning(e.Message);
		}
	}
	*/



	// Use this for initialization
	void Start () {
		//信号を受信したときに、そのメッセージの処理を行う
		serialHandler.OnDataReceived += OnDataReceived;
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}