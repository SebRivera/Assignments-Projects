import ij.*;
import ij.plugin.filter.*;
import ij.process.ImageProcessor;

public class PluginB implements PlugInFilter {

    public int setup(String args, ImagePlus im) {
        return DOES_8G;
    }

    public void run(ImageProcessor ip) {
        int M = ip.getWidth();
        int N = ip.getHeight();

        //get histogram
        int[] hist = ip.getHistogram();

        //median of histogram
        int median = 0;
        for (int i = 0; i < hist.length; i++) {
            median += hist[i] * i;
        }
        //set median to middle of histogram 
        median /= ip.getPixelCount();

        //threshold at median
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (ip.getPixel(i, j) >= median) {
                    ip.putPixel(i, j, 255);
                } else {
                    ip.putPixel(i, j, 0);
                }
            }
        }
    }
}
