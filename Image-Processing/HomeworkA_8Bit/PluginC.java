import ij.ImagePlus;
import ij.*;
import ij.plugin.filter.PlugInFilter;
import ij.process.ImageProcessor;
import java.lang.Math;

public class PluginC implements PlugInFilter {

    public int setup(String args, ImagePlus im) {
        return DOES_8G;
    }

    public void run(ImageProcessor ip) {
        int M = ip.getWidth();
        int N = ip.getHeight();

        double Gamma = 2;

        for (int u = 0; u < M; u++) {
            for (int v = 0; v < N; v++) {
                int r = ip.getPixel(u, v);
		double rd = (double)r;
                ip.putPixel(u, v, (int)(255 * Math.pow(rd/255,Gamma)));
            }
        }
    }
}
