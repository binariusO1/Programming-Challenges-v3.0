/*
2020-05-15 binariusO1
Programing challenge
Image to ASCII
*/

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>							//to save file

using namespace std;
using namespace cv;

void color(Mat&foo)
{
	int x = 100, y = 120;
	unsigned char* p = foo.ptr(y, x); // Y first, X after
	p[0] = 0;   // B
	p[1] = 0;   // G
	p[2] = 255; // R

}

void draw_ASCII(float scale, const Mat & image)
{
	if (remove("asciiImage.txt") == 0)
		perror("Error deleting file *- ");
	else
		puts("File successfully loaded");
	cout << endl;
	ofstream asciiImage("ASCII_image.txt");

	//invert color you want
	//char arr[] = " .,:;ox%#@";
	char arr[] = "@#%xo;:,. ";


	Mat temp;
	resize(image, temp, Size(), scale, scale, 2);

	//namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	//imshow("Display window", temp);        
	//moveWindow("Display window", 600, 600);// Show our image inside it.
	//waitKey(0); // Wait for a keystroke in the window

	cout << "ASCII image width: " << static_cast<int>( image.cols*scale ) << endl;
	cout << "ASCII image height: " << static_cast<int> (image.rows*scale ) << endl;

	if (asciiImage.is_open())
	{
		for (int i = 0; i < static_cast<int>(image.rows *scale); i++)
		{
			for (int j = 0; j < static_cast<int>(image.cols*scale); j++)
			{
				//IMPORTANT: HEIGHT , WIDTH
				Scalar intensity = temp.at<uchar>(i, j);
				uchar blue = static_cast<uchar>(intensity.val[0]);
				asciiImage << arr[static_cast<unsigned>(blue / 26)];
			}
			asciiImage << endl;
		}
	}
	asciiImage.close();
	cout << endl;
	cout << "ASCII image successfully created" << endl;
}

int main(int argc, char** argv)
{

	String imageName("sample.jpg"); // by default
	if (argc > 1)
	{
		imageName = argv[1];
	}

	Mat image;
	image = imread( samples::findFile(imageName), IMREAD_GRAYSCALE ); // Read the file


	if (image.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1; 
	}

	float scale=1.0;
	cout << "Image width: " << image.cols << endl;
	cout << "Image height: " << image.rows << endl;

	while (true) {
		cout << "Give a scale for ASCII image (from 0.01 to 2.0)" << "  for e.g. 0.25" << endl;
		cout << "(press enter to choose default scale 1.0)" << endl;

		std::string input;
		getline(cin, input);

		if (!input.empty()) {
			if (strtof(input.c_str(), NULL) >= 0.1 && strtof(input.c_str(), NULL) <= 2.00) {
				scale = strtof(input.c_str(), NULL);
				break;
			}
		}
		else {
			scale = 1.0;
			break;
		}
	}

	draw_ASCII(scale,image);

	//screen window
	//namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	//moveWindow("Display window", 600, 600);
	//imshow("Display window", image);                // Show our image inside it.
	//waitKey(0); // Wait for a keystroke in the window
	return 0;
}