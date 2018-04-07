package thinkreed.kcanvas;

import android.opengl.GLSurfaceView;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by thinkreed on 2018/4/7.
 */
public class GLRender implements GLSurfaceView.Renderer {

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        KCanvasJni.init();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        KCanvasJni.resize(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        KCanvasJni.step();
    }
}
