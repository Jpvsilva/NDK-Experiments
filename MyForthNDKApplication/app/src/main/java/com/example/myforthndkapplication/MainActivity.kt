package com.example.myforthndkapplication

import android.content.Context
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.myforthndkapplication.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()

        binding.basicCButton.setOnClickListener{
            openEmptyActivity(this)
        }

        binding.bitwiseButton.setOnClickListener{
            openEmptyActivity(this)
        }

        binding.arrayButton.setOnClickListener{
            openEmptyActivity(this)
        }

        binding.conditionalButton.setOnClickListener{
            openEmptyActivity(this)
        }

        binding.switchButton.setOnClickListener{
            openEmptyActivity(this)
        }

        binding.fileButton.setOnClickListener{
            openFileActivity(this)
        }

        binding.pointerButton.setOnClickListener{
            openEmptyActivity(this)
        }

        binding.numberButton.setOnClickListener{
            openEmptyActivity(this)
        }

        binding.loopButton.setOnClickListener{
            openEmptyActivity(this)
        }

        binding.ifElseButton.setOnClickListener{
            openEmptyActivity(this)
        }

        binding.functionButton.setOnClickListener{
            openEmptyActivity(this)
        }

        binding.stringButton.setOnClickListener{
            openEmptyActivity(this)
        }
    }

    /**
     * A native method that is implemented by the 'myforthndkapplication' native library,
     * which is packaged with this application.
     */
    private external fun stringFromJNI(): String

    private external fun openEmptyActivity(context: Context)

    private external fun openFileActivity(context: Context)

    companion object {
        // Used to load the 'myforthndkapplication' library on application startup.
        init {
            System.loadLibrary("myforthndkapplication")
        }
    }
}