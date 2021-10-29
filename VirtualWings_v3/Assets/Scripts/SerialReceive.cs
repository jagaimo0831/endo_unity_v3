/*
	シリアル通信のテストスクリプト：Arduinoからのテキストを表示する
*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SerialReceive : MonoBehaviour {

	public SerialHandler serialHandler;
	public Text text;

	[SerializeField] private int threshold = 600;

	// Use this for initialization
	void Start () {
		//信号を受信したときに、そのメッセージの処理を行う
		serialHandler.OnDataReceived += OnDataReceived;
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	//シリアルを受け取った時の処理
	void OnDataReceived(string message) {
		try {
			int message2 = int.Parse(message);
			Debug.Log(message);

			if(message2 > threshold){
				text.text = message; // シリアルの値をテキストに表示
			}

			
		} catch (System.Exception e) {
			Debug.LogWarning(e.Message);
		}
	}
}