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
                GetComponent<Rigidbody>().AddRelativeForce(0,message2/YForce,message2/ZForce);  // アタッチされているオブジェクトに力を加える
            }
            
        }catch(System.Exception e){
            Debug.LogWarning(e.Message);
        }
    }

	// シリアル通信のためのsomething
    public SerialHandler serialHandler;

    [SerializeField] public float span = 0.01f;
    private float delta = 0;
    [SerializeField] public float YForce = 0.1f;
    [SerializeField] public float ZForce = 0.1f;
    
    //[SerializeField] public float YSpeed = 0.1f;
    //[SerializeField] private int threshold = 500; //筋電値がこの値を超えたら一定速度で進む(物理が無いと起用)
	void Start () {
        // シリアル通信関連:信号を受信したときに、そのメッセージの処理を行う
        serialHandler.OnDataReceived += OnDataReceivedAnalog;
	}

	void Update () {  
    }
}

