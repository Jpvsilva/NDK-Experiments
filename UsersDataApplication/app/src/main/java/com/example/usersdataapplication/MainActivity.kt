package com.example.usersdataapplication

import android.content.Intent
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.example.usersdataapplication.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private val TAG = this::class.java.simpleName
    private lateinit var binding: ActivityMainBinding

    private val EXTRA_MESSAGE = "Boas"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        val message = "Hello!"
        binding.greetingTextView.text = getWelcomeGreeting()
        binding.nextButton.setOnClickListener {
            Log.d(TAG,"Next Button Pressed")
            val intent = Intent(this, UsersActivity::class.java).apply {
                putExtra(EXTRA_MESSAGE, message)
            }
            startActivity(intent)
        }

        binding.crashButton.setOnClickListener {
            throw RuntimeException("Test Crash") // Force a crash
        }
/*
        binding.jsonButton.setOnClickListener {
            Log.d(TAG,"Json Parser Pressed")
            val intent = Intent(this, JsonReader::class.java).apply {
                putExtra(EXTRA_MESSAGE, message)
            }
            startActivity(intent)
        }*/

        binding.ndkCrashButton.setOnClickListener {
            Log.d(TAG,"NDK crash button pressed")
            getNDKCrash()
        }
    }

    private external fun getWelcomeGreeting(): String
    private external fun getNDKCrash()

    companion object {
        // Used to load the 'usersdataapplication' library on application startup.
        init {
            System.loadLibrary("usersdataapplication")
        }
    }
}