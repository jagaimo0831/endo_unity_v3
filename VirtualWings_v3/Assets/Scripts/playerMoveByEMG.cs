using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI; 

public class playerMoveByEMG : MonoBehaviour {

    
    // シリアルを受け取った時の処理
    /*
    //筋電値を閾値によって分けて挙動を制御(デジタル)
	void OnDataReceived(string message) {
		try {
            // string型をint型にキャスト？<- 代入するため
            int message2 = int.Parse(message);

            // 筋電値が一定以上超えたら動作
            if(message2 > threshold){
                var pos = transform.position;
                pos += transform.forward * YSpeed;
                transform.position = pos;
            }
		} catch (System.Exception e) {
			Debug.LogWarning(e.Message);
		}
	}
    */


    //筋電値(力)に比例した力を与える(アナログ)
    
    void OnDataReceivedAnalog(string message){
        try{
            this.delta += Time.deltaTime;
            int message2 = int.Parse(message);
            if (this.delta > this.span) {
                this.delta = 0;
                //float force = 1024*((Mathf.Exp(message2/1024) - Mathf.Exp(-message2/1024)) / (Mathf.Exp(message2/1024) + Mathf.Exp(-message2/1024)));
                // message2が1024に近づくほど増加率が減る．サチる．1024*tanh(x/1024)
                //this.force = 1024 * Mathf.Atan(message2/1024);
                if(message2 <= 800) {
                    this.force = message2;
                } else if (message2 > 800) {
                    this.force = 800;
                } 
                Debug.Log(force);
                GetComponent<Rigidbody>().AddRelativeForce(0,force/YForceDiv,force/ZForceDiv);  // アタッチされているオブジェクトに力を加える
            }
            
        }catch(System.Exception e){
            Debug.LogWarning(e.Message);
        }
    }

	// シリアル通信のためのsomething
    public SerialHandler serialHandler;

    [SerializeField] public float span = 0.01f;
    private float delta = 0;

    private float force = 0;
    
    [SerializeField] public float YForceDiv = 1.0f;
    [SerializeField] public float ZForceDiv = 1.0f;
    
    //[SerializeField] public float YSpeed = 0.1f;
    //[SerializeField] private int threshold = 500; //筋電値がこの値を超えたら一定速度で進む(物理が無いと起用)
	void Start () {
        // シリアル通信関連:信号を受信したときに、そのメッセージの処理を行う
        serialHandler.OnDataReceived += OnDataReceivedAnalog;
	}

	void Update () {
    }
}

