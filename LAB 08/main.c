#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 3

typedef struct s_matrix
{
	double	matrix[ARRAY_SIZE][ARRAY_SIZE];
} matrix;

typedef struct {
    double x;
    double y;
    double z;
} vector;

typedef struct {
    double arr[4];
} third_order_polynominal;

typedef struct {
    double arr[7];
} polynominal;


void	print_matrix(matrix initial_matrix);
int		inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix);
double	determinant_of_matrix(matrix *initial_matrix);
double	find_orthogonal(vector vec_1, vector vec_2, vector* output_vec);
double part2(vector vec_1, vector vec_2, vector* output_vec);
polynominal calculate_integral(third_order_polynominal poly1, third_order_polynominal poly2, int a, int b);


int main(void)
{
	int		error_code; // 1 - success, -1 - error
	matrix	initial_matrix; // initial matrix
	matrix	inverted_matrix; // inverted matrix
	vector	vec_1; // first vector 
	vector	vec_2; // second vecto r
	vector	output_vec; // orthogonal vector

	for (int i = 0; i < ARRAY_SIZE; i++){ // filling the matrix
		for (int j = 0; j < ARRAY_SIZE; j++){   
			printf("Enter the element [%d][%d] of the matrix: ", i, j); 
			scanf("%lf", &initial_matrix.matrix[i][j]);
		}
		
	}
    printf("INITIAL MATRIX :\n");
	print_matrix(initial_matrix); // printing the matrix
	printf("INVERSE MATRIX :\n");
	error_code = inverse_matrix(&initial_matrix, &inverted_matrix); // inverting the matrix
	if (error_code != -1)
		print_matrix(inverted_matrix); // printing the inverted matrix

int x, y, z;
    printf("Please enter the first vector (x y z): "); 
    scanf("%d %d %d", &x, &y, &z); 
    vector vec1 = {x, y, z};
    printf("Please enter the second vector (x y z): "); 
    scanf("%d %d %d", &x, &y, &z);
    vector vec2 = {x, y, z};
    vector orthogonal_vec; 

    double angle = part2(vec1, vec2, &orthogonal_vec); 

    printf("Angle between vec1 and vec2: %.2f degrees\n", angle); 
    printf("Orthogonal vector: (%.2f, %.2f, %.2f)\n", orthogonal_vec.x, orthogonal_vec.y, orthogonal_vec.z);

	


 int a, b;
    polynominal integrated;
    third_order_polynominal poly1;
    third_order_polynominal poly2;

    printf("Enter the variables of first polynom in order x^0 to x^3: ");
    scanf("%lf %lf %lf %lf", &poly1.arr[0], &poly1.arr[1], &poly1.arr[2], &poly1.arr[3]);

    printf("Enter the variables of second polynom in order x^0 to x^3: ");
    scanf("%lf %lf %lf %lf", &poly2.arr[0], &poly2.arr[1], &poly2.arr[2], &poly2.arr[3]);

    printf("Please enter the interval that is used in integral (a, b): ");
    scanf("%d %d", &a, &b);

    integrated = calculate_integral(poly1, poly2, a, b);

    double upper = 0,lower = 0;
    for (int i = 0; 6 >= i ; i++)
    {
        lower += integrated.arr[i]*pow(a,i+1);
        upper += integrated.arr[i]*pow(b,i+1);
    }
    double diff = upper - lower;
    printf("%lf", diff);
	return (0); 
}

int inverse_matrix(matrix* initial_matrix, matrix *inverted_matrix){ // inverting the matrix
	double determinant = determinant_of_matrix(initial_matrix); // finding the determinant
	if (determinant == 0) {
		printf("WARNING!: the matrix is not invertible.\n"); // if the determinant is 0, the matrix is not invertible
		return (-1);
	} 
	double a = initial_matrix->matrix[0][0]; // finding the inverted matrix
	double b = initial_matrix->matrix[0][1]; 
	double c = initial_matrix->matrix[0][2];
	double d = initial_matrix->matrix[1][0];
	double e = initial_matrix->matrix[1][1];
	double f = initial_matrix->matrix[1][2];
	double g = initial_matrix->matrix[2][0];
	double h = initial_matrix->matrix[2][1];
	double i = initial_matrix->matrix[2][2];
	double inv_det = 1.0 / determinant;
	inverted_matrix->matrix[0][0] = inv_det * (e*i - f*h);  
	inverted_matrix->matrix[0][1] = inv_det * (c*h - b*i);
	inverted_matrix->matrix[0][2] = inv_det * (b*f - c*e);
	inverted_matrix->matrix[1][0] = inv_det * (f*g - d*i);
	inverted_matrix->matrix[1][1] = inv_det * (a*i - c*g);
	inverted_matrix->matrix[1][2] = inv_det * (c*d - a*f);
	inverted_matrix->matrix[2][0] = inv_det * (d*h - e*g);
	inverted_matrix->matrix[2][1] = inv_det * (b*g - a*h);
	inverted_matrix->matrix[2][2] = inv_det * (a*e - b*d);
	return (1);
}

void	print_matrix(matrix initial_matrix) // printing the matrix
{
	for (int i = 0; i < ARRAY_SIZE; i++) 
	{
		for (int j = 0; j < ARRAY_SIZE; j++) 
			printf("%.4f\t", initial_matrix.matrix[i][j]); 
		printf("\n");
	}

	return ;
}

double determinant_of_matrix(matrix *initial_matrix){  // finding the determinant
	double a = initial_matrix->matrix[0][0]; // finding the total determinant
	double b = initial_matrix->matrix[0][1];
	double c = initial_matrix->matrix[0][2]; 
	double d = initial_matrix->matrix[1][0];
	double e = initial_matrix->matrix[1][1];
	double f = initial_matrix->matrix[1][2];
	double g = initial_matrix->matrix[2][0];
	double h = initial_matrix->matrix[2][1];
	double i = initial_matrix->matrix[2][2];
	double det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g); // finding the determinant
	return (det); // returning the determinant
}

//==================================PART2==================================


double part2(vector vec_1, vector vec_2, vector* output_vec){
	double dot_product=vec_1.x*vec_2.x+vec_1.y*vec_2.y+vec_1.z*vec_2.z;  /*I am just making the process*/
    double vec1_norm=sqrt(vec_1.x*vec_1.x+vec_1.y*vec_1.y+vec_1.z*vec_1.z);  
    double vec2_norm=sqrt(vec_2.x*vec_2.x+vec_2.y*vec_2.y+vec_2.z*vec_2.z); /*easier by using the dot product and the norms*/
    double angle=acos(dot_product/(vec1_norm*vec2_norm))*180.0/M_PI; /*easier by using the dot product and the norms*/

    output_vec->x=vec_1.y*vec_2.z-vec_1.z*vec_2.y;  /*I am just making the process*/
    output_vec->y=vec_1.z*vec_2.x-vec_1.x*vec_2.z;
    output_vec->z=vec_1.x*vec_2.y-vec_1.y*vec_2.x;

    return angle; /*returning the angle*/
}

double	find_orthogonal(vector vec_1, vector vec_2, vector* output_vec){ 
	double	skaler; // scalar product

	skaler = (vec_1.x * vec_2.x) + (vec_1.y * vec_2.y) + (vec_1.z * vec_2.z); // finding the scalar product
   return 1; // returning the orthogonal vector
}


polynominal calculate_integral(third_order_polynominal poly1, third_order_polynominal poly2, int a, int b)
{
    double multiplied[7];
    double result_integral[7];
    
    polynominal res_poly;
    polynominal poly;

    for (int i=0 ; 6>=i ; i++)
    {
        poly.arr[i] = 0;
        for (int j=0; j<=3 ; j++)
            if (i-j >= 0)
                poly.arr[i] += poly1.arr[j]*poly2.arr[i-j];
    }
    for (int i = 0; i < 7; i++)
        res_poly.arr[i] = poly.arr[i] / (i+1);

    // for (int i = 0; i < 7; i++)
    //     printf("%lf ", res_poly.arr[i]);
    // printf("\n");
    // for (int i = 0; i < 7; i++)
    //     printf("%lf ", poly.arr[i]);
    // printf("\n");
    return res_poly;
}