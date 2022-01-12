package com.example.myforthndkapplication

import android.os.Build
import android.os.Bundle
import android.os.Environment
import android.text.method.ScrollingMovementMethod
import android.widget.Toast
import androidx.annotation.Keep
import androidx.appcompat.app.AppCompatActivity
import com.example.myforthndkapplication.databinding.FileActivityBinding

class FileActivity : AppCompatActivity() {

    private lateinit var binding: FileActivityBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = FileActivityBinding.inflate(layoutInflater)
        setContentView(binding.root)
        checkPermissions()

        val filePath = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS).path
        binding.createFileButton.setOnClickListener {
            val data = "----------------------\nHello From JNI\n"+getCompiledAPI()
            createFile(filePath, data)
        }

        val example = "Boas From JNI"
        binding.fileOutputTextView.text = example
        binding.fileOutputTextView.movementMethod = ScrollingMovementMethod()
        binding.fileOutputTextView.setOnClickListener {
            binding.fileOutputTextView.text = readFileText(filePath)
        }

        binding.appendFileButton.setOnClickListener {
            appendToFile(filePath,"Boas\n")
        }
    }

    /**
     * Checks Write Permissions
     */
    private fun checkPermissions() {
        if (!PermissionsHelper.hasPermission(this)) {
            PermissionsHelper.requestPermission(this)
        }
    }

    /**
     * After Requesting Permission if Write Permission are given
     * @param requestCode Request Code sent by requestPermission
     * @param permissions Permissions to be given
     * @param grantResults Result of permissions given (PERMISSION_GRANTED or PERMISSION_DENIED)
     */
    override fun onRequestPermissionsResult(
        requestCode: Int,
        permissions: Array<String?>,
        grantResults: IntArray
    ) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        if (!PermissionsHelper.hasPermission(this)) {
            // Use toast instead of snackbar here since the activity will exit.
            Toast.makeText(
                this,
                "Permission are needed to run this application",
                Toast.LENGTH_LONG
            )
                .show()
            if (!PermissionsHelper.shouldShowRequestPermissionRationale(this)) {
                // Permission denied with checking "Do not ask again".
                PermissionsHelper.launchPermissionSettings(this)
            }
            finish()
        }
    }

    @Keep
    fun getBuildVersion():String{
        return Build.VERSION.SDK_INT.toString()
    }

    @Keep
    fun getModel(): String {
        val manufacturer = Build.MANUFACTURER // Samsung
        val model = Build.MODEL  // SM-G780
        return "$manufacturer $model" // Samsung SM-G780
    }

    private external fun getCompiledAPI(): String?

    private external fun createFile(path : String, data: String): String?

    private external fun appendToFile(path : String, data: String): String?

    private external fun readFileText(path: String):String
}