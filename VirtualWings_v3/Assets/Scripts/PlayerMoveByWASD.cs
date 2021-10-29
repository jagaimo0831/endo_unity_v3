using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMoveByWASD : MonoBehaviour
{
    [SerializeField] public float XSpeed = 0.1f;
    [SerializeField] public float YSpeed = 0.1f;

    // Update is called once per frame
    void Update()
    {
        var pos = transform.position;
        pos += transform.right * Input.GetAxis("Horizontal") * XSpeed;
        pos += transform.forward * Input.GetAxis("Vertical") * YSpeed;
        transform.position = pos;
    }
}
