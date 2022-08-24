import ij.ImagePlus;
import ij.plugin.filter.PlugInFilter;
import ij.process.ImageProcessor;
import java.lang.Math;

public class PluginA implements PlugInFilter {

    public int setup(String args, ImagePlus im) {
        return DOES_8G;
    }

    public void run(ImageProcessor ip) {
        int M = ip.getWidth();
        int N = ip.getHeight();
        // iterate over all image coordinates (u,v)
        for (int u = 0; u < M; u++) {
            for (int v = 0; v < N; v++) {
                int r = ip.getPixel(u, v);
                ip.putPixel(u, v, 16 * (int)Math.sqrt(r));
            }
        }
    }
}