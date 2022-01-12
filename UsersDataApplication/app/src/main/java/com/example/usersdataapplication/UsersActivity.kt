package com.example.usersdataapplication

import android.content.Intent
import android.os.Build
import android.os.Bundle
import android.os.Environment
import android.util.Log
import androidx.annotation.Keep
import androidx.appcompat.app.AppCompatActivity
import com.example.usersdataapplication.databinding.UserActivityBinding

class UsersActivity : AppCompatActivity() {

    private val TAG = this::class.java.simpleName
    private lateinit var binding: UserActivityBinding
    private val usersDB = UsersDB

    private val EXTRA_MESSAGE = "Boas2"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = UserActivityBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val filePath = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS).path
        //val filePath = filesDir.path
        saveUserToFile(filePath, "----------------------\nHello From JNI\n")
        getCompiledAPI()?.let { saveUserToFile(filePath, it) }

        val user = usersDB.createUser("José", 3.526F)
        binding.usersTextView.text = usersDB.printUserData(user)
        Log.d(TAG, filePath)

        binding.addButton.setOnClickListener {
            Log.d(TAG, "Add Button Pressed")
            usersDB.addBalance(5f, user)
            binding.usersTextView.text = usersDB.printUserData(user)
            saveUserToFile(filePath, user.toString())
        }

        binding.subtractButton.setOnClickListener {
            Log.d(TAG, "Subtract Button Pressed")
            usersDB.removeBalance(5f, user)
            binding.usersTextView.text = usersDB.printUserData(user)
            saveUserToFile(filePath, user.toString())
        }

        binding.readFileButton.setOnClickListener {
            Log.d(TAG,"Next Button Pressed")
            val message = "Hello!"
            val intent = Intent(this, FileActivity::class.java).apply {
                putExtra(EXTRA_MESSAGE, message)
            }
            startActivity(intent)
        }
    }

    private external fun saveUserToFile(path: String, user: String): String?

    private external fun getCompiledAPI(): String?

    @Keep
    fun getBuildVersion():String{
        return Build.VERSION.SDK_INT.toString()
    }

    @Keep
    fun getRuntimeMemorySize(): String {
        return Runtime.getRuntime().freeMemory().toString()
    }

    @Keep
    fun getModel(): String {
        val manufacturer = Build.MANUFACTURER // Samsung
        val model = Build.MODEL  // SM-G780
        return "$manufacturer $model" // Samsung SM-G780
    }
}