package com.example.myforthndkapplication

import android.Manifest
import android.app.Activity
import android.content.Intent
import android.content.pm.PackageManager
import android.net.Uri
import android.provider.Settings
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat

object PermissionsHelper {
    private const val PERMISSION_CODE = 0
    private const val WRITE_PERMISSION = Manifest.permission.WRITE_EXTERNAL_STORAGE

    /** Check to see we have the necessary permissions for this app.  */
    fun hasPermission(activity: Activity?): Boolean {
        return (ContextCompat.checkSelfPermission(activity!!, WRITE_PERMISSION)
                == PackageManager.PERMISSION_GRANTED)
    }

    /** Check to see we have the necessary permissions for this app, and ask for them if we don't.  */
    fun requestPermission(activity: Activity?) {
        ActivityCompat.requestPermissions(
            activity!!, arrayOf(WRITE_PERMISSION), PERMISSION_CODE
        )
    }

    /** Check to see if we need to show the rationale for this permission.  */
    fun shouldShowRequestPermissionRationale(activity: Activity?): Boolean {
        return ActivityCompat.shouldShowRequestPermissionRationale(activity!!,
            WRITE_PERMISSION
        )
    }

    /** Launch Application Setting to grant permission.  */
    fun launchPermissionSettings(activity: Activity) {
        val intent = Intent()
        intent.action = Settings.ACTION_APPLICATION_DETAILS_SETTINGS
        intent.data = Uri.fromParts("package", activity.packageName, null)
        activity.startActivity(intent)
    }
}