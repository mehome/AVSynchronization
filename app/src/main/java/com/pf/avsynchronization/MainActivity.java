package com.pf.avsynchronization;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.SurfaceView;
import android.view.View;

import java.io.File;

public class MainActivity extends AppCompatActivity {

    private PfPlayer pfPlayer;
    private SurfaceView surfaceView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        surfaceView = (SurfaceView) findViewById(R.id.surface);
        pfPlayer = new PfPlayer(surfaceView);
    }

    public void player(View view) {
//        pfPlayer.playJava("rtmp://live.hkstv.hk.lxdns.com/live/hks");
        pfPlayer.playJava("rtmp://47.94.141.202/myapp/mystream");

        //这个文件在assets下里,放入手机外置卡根目录下即可
//        File file = new File(Environment.getExternalStorageDirectory(), "Warcraft3_End.avi");
//        pfPlayer.playJava(file.getAbsolutePath());
    }

    public void stop(View view) {
        pfPlayer.release();
    }
}