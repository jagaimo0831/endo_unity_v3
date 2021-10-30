/* 
    内容
        力を入れている間はsin関数で振動
        力を抜くと止まる
        （ストップウォッチを使用して，止まった場所から続けて動くようにする）
        
        countTime += x * Time.deltaTime; をいじることで周期を変更できる
        _angleで角度を調整
*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI; 

public class MoveWingsLeft_serial : MonoBehaviour {

	// シリアル通信のためのsomething
        public SerialHandler serialHandler;

    // ストップウォッチ関連
        public static float countTime;
            

    // 円運動・振動関連
        // 中心点
        [SerializeField] private Vector3 _center = Vector3.zero;  // 初期値 Vector3(0,0,0) を代入

        // 回転軸
        [SerializeField] private Vector3 _axis = Vector3.up;  // 初期値 Vector(0,1,0) を代入 

        // 円運動周期
        private float _period = 2; //手動調整になりそう

        // 円運動角度
        [SerializeField] private float _angle = 240;

    //sinの宣言
    private float sin;

    [SerializeField] private int threshold = 500;

    

	void Start () {
		// シリアル通信関連
            //信号を受信したときに、そのメッセージの処理を行う
            serialHandler.OnDataReceived += OnDataReceived;

        // ストップウォッチ関連
            countTime = 0;
	}
	

	void Update () { 
        // 翼の振動のためのSin関数の宣言
        sin = Mathf.Sin(countTime);

        // VirtualWings の位置を取得
        _center = GameObject.Find("VirtualWings").transform.position;

        // VirtualWings のy軸を取得
        _axis = GameObject.Find("VirtualWings").transform.up;      
    }

    // シリアルを受け取った時の処理
	void OnDataReceived(string message) {
		try {
            // string型をint型にキャスト？<- 代入するため
            int message2 = int.Parse(message);

            // 筋電値が一定以上超えたら動作
            if(message2 > threshold){
                // ストップウォッチ加算
                countTime += 3 * Time.deltaTime; // ここをいじることで周期を調整


                // 翼を動作させる関数（メソッド？）
                transform.RotateAround( // Vecrot3 point, Vectorr3 axis, float angle
                    _center,
                    _axis,
                    _angle * sin / _period * Time.deltaTime
                );
            }
		} catch (System.Exception e) {
			Debug.LogWarning(e.Message);
		}
	}


}

