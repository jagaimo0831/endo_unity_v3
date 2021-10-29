using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI; 

public class playerMoveByEMG : MonoBehaviour {

	// シリアル通信のためのsomething
        public SerialHandler serialHandler;

    [SerializeField] public float YSpeed = 0.1f;

	void Start () {
		// シリアル通信関連
            //信号を受信したときに、そのメッセージの処理を行う
            serialHandler.OnDataReceived += OnDataReceived;
	}
	

	void Update () {  
    }

    // シリアルを受け取った時の処理
	void OnDataReceived(string message) {
		try {
            // string型をint型にキャスト？<- 代入するため
            int message2 = int.Parse(message);

            // 筋電値が一定以上超えたら動作
            if(message2 > 600){
                var pos = transform.position;
                pos += transform.forward * YSpeed;
                transform.position = pos;
            }
		} catch (System.Exception e) {
			Debug.LogWarning(e.Message);
		}
	}


}

