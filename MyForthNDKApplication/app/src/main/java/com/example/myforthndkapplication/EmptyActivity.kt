package com.example.myforthndkapplication

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.myforthndkapplication.databinding.NotYetImplementedBinding

class EmptyActivity : AppCompatActivity() {
    private lateinit var binding: NotYetImplementedBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = NotYetImplementedBinding.inflate(layoutInflater)
        setContentView(binding.root)
    }
}