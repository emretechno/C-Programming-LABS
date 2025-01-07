#include <stdio.h>
#include <math.h>
#define pi 3.14



int main() {
    
    double surface_area , volume;
    double edge_lenght;
    double a_prism,b_prism,c_prism;
    double r_sphere;
    double r_cone , height_cone, b_cone;
    printf("Please enter the edge length of the cube\n");
    scanf("%lf",&edge_lenght);
    surface_area = 6 * edge_lenght * edge_lenght;
    volume = edge_lenght * edge_lenght * edge_lenght;
    printf("Surface area = %.2lf  , Volume = %.2lf\n",surface_area,volume);
    
    printf("Please enter side length for rectangular prism\n");
    scanf("%lf",&a_prism);
    printf("Please enter side width\n");
    scanf("%lf",&b_prism);
    printf("Please enter side height\n");
    scanf("%lf",&c_prism);
    surface_area = 2 * (a_prism*b_prism+ a_prism*c_prism + b_prism*c_prism);
    volume = a_prism * b_prism * c_prism;
    printf("Surface area = %.2lf  , Volume = %.2lf\n",surface_area,volume);
    
    printf("Pleae enter the radius for sphere.\n");
    scanf("%lf",&r_sphere);
    surface_area = 4 * pi * r_sphere * r_sphere;
    volume = (4* pi * r_sphere * r_sphere * r_sphere) /3;
    printf("Surface are = %.2lf  , Volume = %.2lf\n",surface_area,volume);
    
    printf("Please enter the radius for cone.\n");
    scanf("%lf",&r_cone);
    printf("Please enter the height of cone.\n");
    scanf("%lf",&height_cone);
    b_cone = sqrt((r_cone * r_cone) + (height_cone * height_cone));
    surface_area = pi * r_cone * (b_cone+r_cone);
    volume = ( pi * (r_cone * r_cone * height_cone))/3;
    printf("Surface area = %.2lf  , Volume = %.2lf\n",surface_area,volume);
    
    printf("\n\n\n");
    
    return 0;
    
}
