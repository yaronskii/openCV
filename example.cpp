#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
    IplImage* image = 0;
    IplImage* src = 0;
    std::string image_path("photo.jpg");

    if( argc == 2)
        image_path = argv[1];

    // получаем картинку
    image = cvLoadImage(image_path.c_str(), 1);
    // клонируем картинку
    src = cvCloneImage(image);

    printf("[i] image: %s\n", image_path.c_str());
    assert( src != 0 );

    // окно для отображения картинки
    cvNamedWindow("original",CV_WINDOW_AUTOSIZE);

    // показываем картинку
    cvShowImage("original",image);

    // выводим в консоль информацию о картинке
    printf( "[i] channels:  %d\n",        image->nChannels );
    printf( "[i] pixel depth: %d bits\n",   image->depth );
    printf( "[i] width:       %d pixels\n", image->width );
    printf( "[i] height:      %d pixels\n", image->height );
    printf( "[i] image size:  %d bytes\n",  image->imageSize );
    printf( "[i] width step:  %d bytes\n",  image->widthStep );

    // ждём нажатия клавиши
    cvWaitKey(0);

    // освобождаем ресурсы
    cvReleaseImage(& image);
    cvReleaseImage(&src);
    // удаляем окно
    cvDestroyWindow("original");

    return 0;
}
