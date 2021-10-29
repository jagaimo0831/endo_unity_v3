using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MoveWingsRight_auto : MonoBehaviour
{
    // 中心点
    [SerializeField] private Vector3 _center = Vector3.zero;  // 初期値 Vector3(0,0,0) を代入

    // 回転軸
    [SerializeField] private Vector3 _axis = Vector3.up;  // 初期値 Vector(0,1,0) を代入 

    // 円運動周期
    [SerializeField] private float _period = 2;

    // 円運動角度
    [SerializeField] private float _angle = 70;


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        // Sin関数の宣言
        float sin = Mathf.Sin(Time.time); //常に-1~1の値を出力

        _center = GameObject.Find("VirtualWings").transform.position;

        _axis = -1 * GameObject.Find("VirtualWings").transform.up; // ここに-1をかけるとLeftと逆になる
        

        transform.RotateAround( // Vecrot3 point, Vectorr3 axis, float angle
            _center,
            _axis,
            _angle * sin / _period * Time.deltaTime
        );
    }
}
