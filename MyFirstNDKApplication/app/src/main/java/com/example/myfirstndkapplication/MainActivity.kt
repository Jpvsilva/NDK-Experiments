package com.example.myfirstndkapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.myfirstndkapplication.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.button2.setOnClickListener{
            binding.sampleText.text = calculateArea(binding.editTextNumber.text.toString().toDouble())
        }

    }

    /**
     * A native method that is implemented by the 'myfirstndkapplication' native library,
     * which is packaged with this application.
     */
    private external fun stringFromJNI(): String

    companion object {
        // Used to load the 'myfirstndkapplication' library on application startup.
        init {
            System.loadLibrary("myfirstndkapplication")
        }
    }

    private external fun calculateArea(radius: Double): String
}