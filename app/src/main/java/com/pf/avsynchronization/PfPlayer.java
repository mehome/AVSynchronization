package com.pf.avsynchronization;

import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * @author zhaopf
 * @version 1.0
 * @QQ 1308108803
 * @date 2017/10/9
 */

public class PfPlayer implements SurfaceHolder.Callback {
    static {
        System.loadLibrary("avcodec-56");
        System.loadLibrary("avdevice-56");
        System.loadLibrary("avfilter-5");
        System.loadLibrary("avformat-56");
        System.loadLibrary("avutil-54");
        System.loadLibrary("postproc-53");
        System.loadLibrary("swresample-1");
        System.loadLibrary("swscale-3");
        System.loadLibrary("native-lib");
    }

    private SurfaceView surfaceView;

    public PfPlayer(SurfaceView surfaceView) {
        setSurfaceView(surfaceView);
    }

    public void setSurfaceView(SurfaceView surfaceView) {
        this.surfaceView = surfaceView;
        display(surfaceView.getHolder().getSurface());
        surfaceView.getHolder().addCallback(this);
    }

    public void playJava(String path) {
        if (this.surfaceView == null) {
            return;
        }
        play(path);
    }

    private native void play(String path);

    private native void display(Surface surface);

    public native void release();

    @Override
    public void surfaceCreated(SurfaceHolder holder) {}

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        display(holder.getSurface());
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {}
}