#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the color for the sun
    setcolor(YELLOW);

    // Draw the sun
    circle(320, 240, 40);
    floodfill(320, 240, YELLOW);

    // Set colors for each planet
    int planetColors[] = {WHITE, GREEN, BLUE, RED, MAGENTA, BROWN, CYAN, LIGHTRED};

    // Set the radii and speeds for each planet
    int radii[] = {70, 100, 150, 200, 260, 320, 380, 440};
    double speeds[] = {0.1, 0.08, 0.06, 0.04, 0.03, 0.02, 0.015, 0.012};

    // Draw orbits and planets
    for (int i = 0; i < 8; i++) {
        // Calculate planet position
        int x = 320 + radii[i] * cos(speeds[i]);
        int y = 240 + radii[i] * sin(speeds[i]);

        // Draw orbit
        setcolor(WHITE);
        circle(320, 240, radii[i]);

        // Draw planet
        setcolor(planetColors[i]);
        circle(x, y, i + 10);
        floodfill(x, y, planetColors[i]);
    }

    getch();
    closegraph();

    return 0;
}
