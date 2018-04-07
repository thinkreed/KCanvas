package thinkreed.kcanvas;

/**
 * Created by thinkreed on 2018/4/7.
 */
public class KCanvasJni {
    static {
        System.loadLibrary("kcanvas-lib");
    }

    public static native boolean init();

    public static native void resize(int width, int height);

    public static native void step();

    public static native void destroy();
}
