package com.example.barcodegenerator

import android.graphics.Bitmap
import android.graphics.Insets
import android.os.Build
import android.os.Bundle
import android.util.DisplayMetrics
import android.util.Log
import android.view.WindowInsets
import androidx.appcompat.app.AppCompatActivity
import com.example.barcodegenerator.databinding.ActivityMainBinding
import java.util.*

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    private val TAG = MainActivity::class.java.simpleName

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.sampleText.text = stringFromJNI()

        binding.bBarcode.setOnClickListener {
            val textOfInterest =
                "*" + binding.etBarcode.text.toString().uppercase(Locale.getDefault()) + "*"
            Log.i(TAG, "clicked! [$textOfInterest]")

            val width = getScreenWidth()
            val bitmapWip = Bitmap.createBitmap(width - 20, 100, Bitmap.Config.ALPHA_8)
            code39(textOfInterest, bitmapWip)
            binding.ivBarcode.setImageBitmap(bitmapWip)
        }
    }

    private fun getScreenWidth(): Int {
        return if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            val windowMetrics = windowManager.currentWindowMetrics
            val insets: Insets = windowMetrics.windowInsets
                .getInsetsIgnoringVisibility(WindowInsets.Type.systemBars())
            windowMetrics.bounds.width() - insets.left - insets.right
        } else {
            val displayMetrics = DisplayMetrics()
            windowManager.defaultDisplay.getMetrics(displayMetrics)
            displayMetrics.widthPixels
        }
    }

    /**
     * A native method that is implemented by the 'barcodegenerator' native library,
     * which is packaged with this application.
     */
    private external fun code39(
        text: String?,
        bitmap: Bitmap?
    )

    /**
     * A native method that is implemented by the 'barcodegenerator' native library,
     * which is packaged with this application.
     */
    private external fun stringFromJNI(): String

    companion object {
        // Used to load the 'barcodegenerator' library on application startup.
        init {
            System.loadLibrary("barcodegenerator")
        }
    }
}