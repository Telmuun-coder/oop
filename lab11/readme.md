# Universe
Лаб 11
Д.Самдан (16B1SEAS2873)
ХШУИС, ПХ-ийн 3-р түвшин
##1. Оршил
Энэ хичээлийн жилээр сурсан мэдлэгээ ашиглан. Ертөнцийн таталцалын хуулийн симтлацыг С++ хэл дээр хоёр хэмжээст байдалаар үүссэгсэн.

##2. Зорилго
Хоёр хэмжээст тайлбай дээр ертөнцийн таталцалын хуулийн симтлацыг үүсгэх. Үүний тулд дараах зорилтуудыг тавьж ажилласан:
- Body объект байгуулах
- Universe объект байгуулах
  -  файлаас уншиж ертөнцөө байгуулах
  -  Биесийн байршилийг шинэчлэх функц бичих
  -  Физикийн хурдтгал, хурд, зай олон функц бичих
## Онолий  судалгаа
**Файлтэй ажилах:**
```c++
// Файлаас унших, бичихид толгой файл оруулах
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    // 2 параметр файл нээхэд хэрэгтэй
    // 1 дахь файлын нэр
    // 2 ямар горимтой нээхийг заана ios::in or ios::out
    ofstream write_file;
    write_file.open("my.txt", ios::out);
    // Эсвэл 
    ofstream newfile("new.txt", ios::out);
    newfile.close();

    // Нээгдсэн хэсэгийг шалгана
    if (write_file.is_open())
    {
        cout << "My file is open" << endl;

        // Файл руу юм бичнэ
        write_file << "This is a line.\n";
        write_file << "This is another line.\n";

        // Нээсэн файлаа хаана
        write_file.close();
    }
    else
    {
        cout << "Unable to open file!" << endl;
    }

    cout << endl << "***********************";
    cout << endl << "Reading from file" << endl << endl;

    string line;

    // ifstream ээр ашиглан файлаас юм унших
    ifstream read_file("my.txt");
    if (read_file.is_open())
    {
        // getline ийг ашиглах мөр мөрөөр авна
        while ( getline(read_file, line) )
        {
            cout << line << endl;
        }
        read_file.close();
    }

    cout << endl << "***********************";
    cout << endl << "Reading from file (char by char)" << endl << endl;

    char a_char;

    // ifstream ээр ашиглан файлаас юм унших
    ifstream read_file_by_char("my.txt");
    if (read_file_by_char.is_open())
    {
        // get ашиглан тэмдэг тэмдэтээр авна
        while ( read_file_by_char.get(a_char) )
        {
            cout << a_char << ",";
        }
        read_file.close();
    }

    return 0;
}
```
**OpenGL 2 сан:**
OpenGL ашиглахын тулд `<GL/glut.h>` толгой файлыг оруулж өгнө.
Үүн дотор:
Дэлгэц үүсгэх функц:
```c++
// Дэлэгцээ эхлүүлэх
glutInit(&argc, argv);
// Дэлэгцийн горимоо сонгох
glutInitDisplayMode(GLUT_DOUBLE);
// Дэлэгцийн хэмжээг тодорхойлох
glutInitWindowSize(600, 600);
// Дэлэгцийн анхын байрлалыг тодорхйолох
glutInitWindowPosition(800, 100);
// Дэлэгцт нэр өгнө
glutCreateWindow("Universe");
// Дэлэгцийн хэмжээ өөрчилөгдөх яахыг хэлнэ
glutReshapeFunc(resize);
// Дэлэгцэн дээр юм зурна
glutDisplayFunc(displayMe);
// Дэлэгцийн анхы байдалыг тодорхойлно
setup();
// Дэлэгцийн 1 милл секунт тутам функц дуудна
glutTimerFunc(1, timer, 1);
// Дэлэгцийн үзэгдэлийг байга дуудна
glutMainLoop();
```
Үүссэн дэлгэх дээр зурах функц:
```c++
// Хоёр хэмжээст ертөнцийг хэвтээ, босоо чиглэлт 0, 1000 хооронд тодорхойлно
gluOrtho2D(0, 1000, 0, 1000);

// Дүрсээ юугаар зурахыг заана
glBegin(GL_LINE_LOOP);
// Зурахд ямар өнгөөр заахыг заана
glColor3f(1, 1, 1);
for (int i = 0; i < 360; i++) {
	// Хоёр хэмжээст ертөнц дээр а радиустай тойрог зурна
	glVertex2f(x + radius * cos(i * M_PI / 180), y + radius * sin(i * M_PI / 180));
}
glEnd();
```
## Хэрэгжүүлэлт
[Body.h](/Body.h) - Гаригын тухай мэдээлэл байна.
[Universe.h](/Universe.h) - Ерөнцийн тухай мэдээлэл байна.
[main.cpp](/main.cpp) - Ерөнцит байшаа гаригуудын OpenGL ашиглан зурна. Бас 1 мил секунд тутам дараах байрлалыг бодоод шинэ гаригуудын байршилыг зурна.

## Дүгнэлт
Энэ хичээлийн жилээр сурж авсан объект хандлагт програмчилалын суурь мэдлэгээ ашиглан. Ерөтөнцийн таталцалын хуулийн симулаци хээсэн юм. Үүний эцэс бид объект хандлагт програмчлалийн ашиглах бодит програм хангамж хөгжүүлэх боломжтой болсон юм.
