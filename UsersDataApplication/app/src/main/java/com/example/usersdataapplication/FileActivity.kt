package com.example.usersdataapplication

import android.os.Bundle
import android.os.Environment
import android.text.method.ScrollingMovementMethod
import androidx.appcompat.app.AppCompatActivity
import com.example.usersdataapplication.databinding.FileActivityBinding

class FileActivity: AppCompatActivity() {

    private lateinit var binding: FileActivityBinding

    override fun onCreate(savedInstanceState: Bundle?){
        super.onCreate(savedInstanceState)

        binding = FileActivityBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val filePath =
            Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS).path
        val assetsFilePath = filesDir.path
        val example = "Boas From JNI"
        binding.readFileTextView.text = example
        binding.readFileTextView.movementMethod= ScrollingMovementMethod()
        binding.readButton.setOnClickListener {
            binding.readFileTextView.text = readFileText(filePath)
        }
    }

    private external fun readFileText(path: String):String

}