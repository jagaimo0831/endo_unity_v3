using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class testScript : MonoBehaviour
{
    private float message2 = 0;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        this.message2 += 1.0f;
        float force = 1024*((Mathf.Exp(message2/1024) - Mathf.Exp(-message2/1024)) / (Mathf.Exp(message2/1024) + Mathf.Exp(-message2/1024)));
        Debug.Log(force);
    }
}
