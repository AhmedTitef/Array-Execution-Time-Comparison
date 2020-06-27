import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Matrix {


    public static void main(String[] args) {

        driver();

    }

    static int size;
    static float[][] a;
    static float[][] b;
    static float[][] c;

    static void createTwoMatrix(int size) {
        a = new float[size][size];
        b = new float[size][size];
        c = new float[size][size];
    }

    static void fillMatrix(float[][] a, float[][] b) {
        Random random = new Random();
        Random random1 = new Random();

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length; j++) {
                a[i][j] = random.nextFloat();

                b[i][j] = random1.nextFloat();

            }

        }


    }


    static float[][] add(float[][] a, float[][] b) {
        long startTime = System.currentTimeMillis();
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }

        }
        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;
        System.out.println("Time taken to complete this operation is : "+elapsedTime * 1000 + " microseconds");
        return c;
    }

    static float[][] subtract(float[][] a, float[][] b) {
        long startTime = System.currentTimeMillis();
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length; j++) {

                c[i][j] = a[i][j] - b[i][j];
            }

        }
        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;
        System.out.println("Time taken to complete this operation is : "+elapsedTime * 1000 + " microseconds");
        return c;
    }

    static float[][] multiplication(float[][] a, float[][] b) {
        long startTime = System.currentTimeMillis();
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length; j++) {
                for (int x = 0; x < a.length; x++) {
                    c[i][j] += a[i][x] * b[x][j];

                }

            }

        }
        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;
        System.out.println("Time taken to complete this operation is : "+elapsedTime  * 1000+ " microseconds");
        return c;
    }

    static void driver() {
        Scanner scanner = new Scanner( System.in );
        boolean boolValue = true;
        String answerForLoop;
        int options;
        while (boolValue) {
            System.out.println( "HELLO!. Please Follow The Instructions Carefully" );
            System.out.println( "Please Specify The Size of The 2D Array. You Can Input 10 ,  or any integer value" );
            size = scanner.nextInt();
            createTwoMatrix( size );
            fillMatrix( a, b );
            System.out.println( "Two 2D Arrays have been created with same size." );
            System.out.println( "Please Choose From The Following Menu." );
            System.out.println( "Multiplication: Enter 1" );
            System.out.println( "Subtraction: Enter 2" );
            System.out.println( "Addition: Enter 3" );
            options = scanner.nextInt();
            switch (options) {
                case 1:
                    System.out.println( "You chose Multiplication" );
                    System.out.println( "The output is : " );
                    System.out.println( Arrays.deepToString( multiplication( a, b ) ) );

                    break;
                case 2:
                    System.out.println( "You chose Subtraction" );
                    System.out.println( "The output is : " );
                    System.out.println( Arrays.deepToString( subtract( a, b ) ) );
                    break;
                case 3:
                    System.out.println( "You chose Addition" );
                    System.out.println( "The output is : " );
                    System.out.println( Arrays.deepToString( add( a, b ) ) );
                    break;
                default:
                    System.out.println( "Please Choose A Correct Option. The Program Will Exit Now." );
                    System.exit( 3 );
                    break;
            }
            System.out.println( "////////////  END   ////////////////" );
            System.out.println( "Would You Like To Try Another Operation? Please Enter y/n" );
            answerForLoop = scanner.nextLine();
            switch (answerForLoop) {
                case "y":
                    boolValue = true;
                    break;
                case "n":
                    System.out.println( "Thank You & Have A Good Day!" );
                    boolValue = false;
                    break;

                default:
                    System.out.println( "You Choose Wrong Option. The Program Will Exit. Please Try Again Later" );
                    boolValue = false;
                    System.exit( 3 );
                    break;
            }


        }
    }
}
