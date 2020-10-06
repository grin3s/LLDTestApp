package com.gringauz.lldtestapp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import com.google.firebase.crashlytics.FirebaseCrashlytics
import kotlinx.android.synthetic.main.activity_main.*
import java.util.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // setting random id so that it is easy to find crash for session
        val randomUUID = UUID.randomUUID().toString()
        FirebaseCrashlytics.getInstance().setUserId(randomUUID)
        Log.e("CRASHUUID", randomUUID)

        // Example of a call to a native method
        sample_text.text = stringFromJNI()
        sample_text.setOnClickListener {
            crash()
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun crash()

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
