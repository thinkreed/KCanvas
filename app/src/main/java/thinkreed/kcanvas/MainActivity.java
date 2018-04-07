package thinkreed.kcanvas;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private KCanvasView canvasView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        canvasView = new KCanvasView(this);
        setContentView(canvasView);
    }

    @Override
    protected void onPause() {
        super.onPause();
        canvasView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        canvasView.onResume();
    }
}
