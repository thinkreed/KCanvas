package thinkreed.kcanvas;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

/**
 * Created by thinkreed on 2018/4/7.
 */
public class KCanvasView extends GLSurfaceView {

    public KCanvasView(Context context) {
        this(context, null);
    }

    public KCanvasView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    private void init() {
        setEGLConfigChooser(8,8,8,0,16,0);
        setEGLContextClientVersion(3);
        setRenderer(new GLRender());
    }
}
