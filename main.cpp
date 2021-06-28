#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int, int, int, int);
void timer(int);
void mySpecialKeyboard(int, int, int);


int is_depth;

float x = 1, y = 1, z = 1;
int w = 480, h = 480, flag = 0, flg;

int c, d;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Universiteit Bibliotheek KU Leuven");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(1, timer, 0);
    glutSpecialFunc(mySpecialKeyboard);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glLineWidth(3.0f);
}

void menara() {
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.4, 0.1);
    glVertex3f(-20, -20, -30);
    glVertex3f(-10, -20, -30);
    glVertex3f(-10, 70, -30);
    glVertex3f(-20, 70, -30);
    glEnd();

    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.4, 0.1);
    glVertex3f(-20, -20, -20);
    glVertex3f(-10, -20, -20);
    glVertex3f(-10, 70, -20);
    glVertex3f(-20, 70, -20);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.4, 0.1);
    glVertex3f(-20, -20, -30);
    glVertex3f(-20, 70, -30);
    glVertex3f(-20, 70, -20);
    glVertex3f(-20, -20, -20);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.4, 0.1);
    glVertex3f(-10, -20, -30);
    glVertex3f(-10, 70, -30);
    glVertex3f(-10, 70, -20);
    glVertex3f(-10, -20, -20);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.4, 0.1);
    glVertex3f(-20, 70, -30);
    glVertex3f(-20, 70, -20);
    glVertex3f(-10, 70, -20);
    glVertex3f(-10, 70, -30);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex3f(-35, -20, -10);
    glVertex3f(-35, -20, -50);
    glVertex3f(35, -20, -50);
    glVertex3f(35, -20, -10);
    glEnd();
}

void atap_menara() {
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(1.7, 0.4, 0.1);
    glVertex3f(-20, 70, -30);
    glVertex3f(-10, 70, -30);
    glVertex3f(-15, 110, -25);
    glEnd();

    //depan
    glBegin(GL_POLYGON);
    glColor3f(1.7, 0.4, 0.1);
    glVertex3f(-20, 70, -20);
    glVertex3f(-10, 70, -20);
    glVertex3f(-15, 110, -25);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(1.7, 1.4, 0.1);
    glVertex3f(-20, 70, -30);
    glVertex3f(-15, 110, -25);
    glVertex3f(-20, 70, -20);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.4, 1.1);
    glVertex3f(-10, 70, -30);
    glVertex3f(-15, 110, -25);
    glVertex3f(-10, 70, -20);
    glEnd();
}

void bangunankotakdepan() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-50, -20, 10);
    glVertex3f(50, -20, 10);
    glVertex3f(50, 20, 10);
    glVertex3f(-50, 20, 10);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-50, -20, -10);
    glVertex3f(50, -20, -10);
    glVertex3f(50, 20, -10);
    glVertex3f(-50, 20, -10);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-50, -20, 10);
    glVertex3f(-50, 20, 10);
    glVertex3f(-50, 20, -10);
    glVertex3f(-50, -20, -10);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(50, -20, 10);
    glVertex3f(50, 20, 10);
    glVertex3f(50, 20, -10);
    glVertex3f(50, -20, -10);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-50, 20, 10);
    glVertex3f(-50, 20, -10);
    glVertex3f(50, 20, -10);
    glVertex3f(50, 20, 10);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex3f(-50, -20, 10);
    glVertex3f(-50, -20, -10);
    glVertex3f(50, -20, -10);
    glVertex3f(50, -20, 10);
    glEnd();
}

void ataspilar_depan() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60, 0, 20);
    glVertex3f(60, 0, 20);
    glVertex3f(60, 20, 20);
    glVertex3f(-60, 20, 20);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, 10);
    glVertex3f(60, 0, 10);
    glVertex3f(60, 20, 10);
    glVertex3f(-60, 20, 10);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60, 0, 20);
    glVertex3f(-60, 20, 20);
    glVertex3f(-60, 20, 10);
    glVertex3f(-60, 0, 10);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(60, 0, 20);
    glVertex3f(60, 20, 20);
    glVertex3f(60, 20, 10);
    glVertex3f(60, 0, 10);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 20, 20);
    glVertex3f(-60, 20, 10);
    glVertex3f(60, 20, 10);
    glVertex3f(60, 20, 20);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, 20);
    glVertex3f(-60, 0, 10);
    glVertex3f(60, 0, 10);
    glVertex3f(60, 0, 20);
    glEnd();
}

void ataspilar_depankirikanan() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, 10);
    glVertex3f(60, 0, 10);
    glVertex3f(60, 20, 10);
    glVertex3f(-60, 20, 10);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, -10);
    glVertex3f(60, 0, -10);
    glVertex3f(60, 20, -10);
    glVertex3f(-60, 20, -10);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60, 0, 10);
    glVertex3f(-60, 20, 10);
    glVertex3f(-60, 20, -10);
    glVertex3f(-60, 0, -10);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(60, 0, 10);
    glVertex3f(60, 20, 10);
    glVertex3f(60, 20, -10);
    glVertex3f(60, 0, -10);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 20, 10);
    glVertex3f(-60, 20, -10);
    glVertex3f(60, 20, -10);
    glVertex3f(60, 20, 10);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, 10);
    glVertex3f(-60, 0, -10);
    glVertex3f(60, 0, -10);
    glVertex3f(60, 0, 10);
    glEnd();
}

void pilar_depan(float x) {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60 + x, 0, 20);
    glVertex3f(-54 + x, 0, 20);
    glVertex3f(-54 + x, -20, 20);
    glVertex3f(-60 + x, -20, 20);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60 + x, 0, 15);
    glVertex3f(-54 + x, 0, 15);
    glVertex3f(-54 + x, -20, 15);
    glVertex3f(-60 + x, -20, 15);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60 + x, 0, 20);
    glVertex3f(-60 + x, -20, 20);
    glVertex3f(-60 + x, -20, 15);
    glVertex3f(-60 + x, 0, 15);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-54 + x, 0, 20);
    glVertex3f(-54 + x, -20, 20);
    glVertex3f(-54 + x, -20, 15);
    glVertex3f(-54 + x, 0, 15);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60 + x, 20, 20);
    glVertex3f(-60 + x, 20, 15);
    glVertex3f(-54 + x, 20, 15);
    glVertex3f(-54 + x, 20, 20);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60 + x, 0, 20);
    glVertex3f(-60 + x, 0, 15);
    glVertex3f(-54 + x, 0, 15);
    glVertex3f(-54 + x, 0, 20);
    glEnd();
}

void pilar_depankiri(float z) {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60, 0, 20 - z);
    glVertex3f(-54, 0, 20 - z);
    glVertex3f(-54, -20, 20 - z);
    glVertex3f(-60, -20, 20 - z);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, 14 - z);
    glVertex3f(-54, 0, 14 - z);
    glVertex3f(-54, -20, 14 - z);
    glVertex3f(-60, -20, 14 - z);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60, 0, 20 - z);
    glVertex3f(-60, -20, 20 - z);
    glVertex3f(-60, -20, 14 - z);
    glVertex3f(-60, 0, 14 - z);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-54, 0, 20 - z);
    glVertex3f(-54, -20, 20 - z);
    glVertex3f(-54, -20, 14 - z);
    glVertex3f(-54, 0, 14 - z);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 20, 20 - z);
    glVertex3f(-60, 20, 14 - z);
    glVertex3f(-54, 20, 14 - z);
    glVertex3f(-54, 20, 20 - z);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, 20 - z);
    glVertex3f(-60, 0, 14 - z);
    glVertex3f(-54, 0, 14 - z);
    glVertex3f(-54, 0, 20 - z);
    glEnd();
}

void pilar_depankanan(float z) {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(60, 0, 20 - z);
    glVertex3f(54, 0, 20 - z);
    glVertex3f(54, -20, 20 - z);
    glVertex3f(60, -20, 20 - z);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(60, 0, 14 - z);
    glVertex3f(54, 0, 14 - z);
    glVertex3f(54, -20, 14 - z);
    glVertex3f(60, -20, 14 - z);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(60, 0, 20 - z);
    glVertex3f(60, -20, 20 - z);
    glVertex3f(60, -20, 14 - z);
    glVertex3f(60, 0, 14 - z);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(54, 0, 20 - z);
    glVertex3f(54, -20, 20 - z);
    glVertex3f(54, -20, 14 - z);
    glVertex3f(54, 0, 14 - z);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(60, 20, 20 - z);
    glVertex3f(60, 20, 14 - z);
    glVertex3f(54, 20, 14 - z);
    glVertex3f(54, 20, 20 - z);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(60, 0, 20 - z);
    glVertex3f(60, 0, 14 - z);
    glVertex3f(54, 0, 14 - z);
    glVertex3f(54, 0, 20 - z);
    glEnd();
}

void bangunankotakbelakang() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-50, -20, -50);
    glVertex3f(50, -20, -50);
    glVertex3f(50, 20, -50);
    glVertex3f(-50, 20, -50);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-50, -20, -70);
    glVertex3f(50, -20, -70);
    glVertex3f(50, 20, -70);
    glVertex3f(-50, 20, -70);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-50, 20, -50);
    glVertex3f(-50, -20, -50);
    glVertex3f(-50, -20, -70);
    glVertex3f(-50, 20, -70);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(50, 20, -50);
    glVertex3f(50, -20, -50);
    glVertex3f(50, -20, -70);
    glVertex3f(50, 20, -70);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-50, 20, -70);
    glVertex3f(-50, 20, -50);
    glVertex3f(50, 20, -50);
    glVertex3f(50, 20, -70);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex3f(-50, -20, -50);
    glVertex3f(-50, -20, -70);
    glVertex3f(50, -20, -70);
    glVertex3f(50, -20, -50);
    glEnd();
}

void ataspilar_belakang() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, -70);
    glVertex3f(60, 0, -70);
    glVertex3f(60, 20, -70);
    glVertex3f(-60, 20, -70);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60, 0, -80);
    glVertex3f(60, 0, -80);
    glVertex3f(60, 20, -80);
    glVertex3f(-60, 20, -80);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60, 0, -70);
    glVertex3f(-60, 20, -70);
    glVertex3f(-60, 20, -80);
    glVertex3f(-60, 0, -80);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(60, 0, -70);
    glVertex3f(60, 20, -70);
    glVertex3f(60, 20, -80);
    glVertex3f(60, 0, -80);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 20, -70);
    glVertex3f(-60, 20, -80);
    glVertex3f(60, 20, -80);
    glVertex3f(60, 20, -70);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, -70);
    glVertex3f(-60, 0, -80);
    glVertex3f(60, 0, -80);
    glVertex3f(60, 0, -70);
    glEnd();
}

void ataspilar_belakangkirikanan() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, -50);
    glVertex3f(60, 0, -50);
    glVertex3f(60, 20, -50);
    glVertex3f(-60, 20, -50);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, -70);
    glVertex3f(60, 0, -70);
    glVertex3f(60, 20, -70);
    glVertex3f(-60, 20, -70);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60, 0, -50);
    glVertex3f(-60, 20, -50);
    glVertex3f(-60, 20, -70);
    glVertex3f(-60, 0, -70);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(60, 0, -50);
    glVertex3f(60, 20, -50);
    glVertex3f(60, 20, -70);
    glVertex3f(60, 0, -70);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 20, -50);
    glVertex3f(-60, 20, -70);
    glVertex3f(60, 20, -70);
    glVertex3f(60, 20, -50);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, -50);
    glVertex3f(-60, 0, -70);
    glVertex3f(60, 0, -70);
    glVertex3f(60, 0, -50);
    glEnd();
}

void pilar_belakang(float x) {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60 + x, 0, -75);
    glVertex3f(-54 + x, 0, -75);
    glVertex3f(-54 + x, -20, -75);
    glVertex3f(-60 + x, -20, -75);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60 + x, 0, -80);
    glVertex3f(-54 + x, 0, -80);
    glVertex3f(-54 + x, -20, -80);
    glVertex3f(-60 + x, -20, -80);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60 + x, 0, -75);
    glVertex3f(-60 + x, -20, -75);
    glVertex3f(-60 + x, -20, -80);
    glVertex3f(-60 + x, 0, -80);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-54 + x, 0, -75);
    glVertex3f(-54 + x, -20, -75);
    glVertex3f(-54 + x, -20, -80);
    glVertex3f(-54 + x, 0, -80);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60 + x, 20, -75);
    glVertex3f(-60 + x, 20, -80);
    glVertex3f(-54 + x, 20, -80);
    glVertex3f(-54 + x, 20, -75);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60 + x, 0, -75);
    glVertex3f(-60 + x, 0, -80);
    glVertex3f(-54 + x, 0, -80);
    glVertex3f(-54 + x, 0, -75);
    glEnd();
}

void pilar_belakangkiri(float z) {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, -50 - z);
    glVertex3f(-54, 0, -50 - z);
    glVertex3f(-54, -20, -50 - z);
    glVertex3f(-60, -20, -50 - z);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60, 0, -56 - z);
    glVertex3f(-54, 0, -56 - z);
    glVertex3f(-54, -20, -56 - z);
    glVertex3f(-60, -20, -56 - z);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-60, 0, -50 - z);
    glVertex3f(-60, -20, -50 - z);
    glVertex3f(-60, -20, -56 - z);
    glVertex3f(-60, 0, -56 - z);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(-54, 0, -50 - z);
    glVertex3f(-54, -20, -50 - z);
    glVertex3f(-54, -20, -56 - z);
    glVertex3f(-54, 0, -56 - z);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 20, -50 - z);
    glVertex3f(-60, 20, -56 - z);
    glVertex3f(-54, 20, -56 - z);
    glVertex3f(-54, 20, -50 - z);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 0, -50 - z);
    glVertex3f(-60, 0, -56 - z);
    glVertex3f(-54, 0, -56 - z);
    glVertex3f(-54, 0, -50 - z);
    glEnd();
}

void pilar_belakangkanan(float z) {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(60, 0, -50 - z);
    glVertex3f(54, 0, -50 - z);
    glVertex3f(54, -20, -50 - z);
    glVertex3f(60, -20, -50 - z);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(60, 0, -56 - z);
    glVertex3f(54, 0, -56 - z);
    glVertex3f(54, -20, -56 - z);
    glVertex3f(60, -20, -56 - z);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(60, 0, -50 - z);
    glVertex3f(60, -20, -50 - z);
    glVertex3f(60, -20, -56 - z);
    glVertex3f(60, 0, -56 - z);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(2.9, 0.8, 0.5);
    glVertex3f(54, 0, -50 - z);
    glVertex3f(54, -20, -50 - z);
    glVertex3f(54, -20, -56 - z);
    glVertex3f(54, 0, -56 - z);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(60, 20, -50 - z);
    glVertex3f(60, 20, -56 - z);
    glVertex3f(54, 20, -56 - z);
    glVertex3f(54, 20, -50 - z);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(60, 0, -50 - z);
    glVertex3f(60, 0, -56 - z);
    glVertex3f(54, 0, -56 - z);
    glVertex3f(54, 0, -50 - z);
    glEnd();
}

void bangunankotaksampingkanan() {
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(35, 20, -50);
    glVertex3f(35, -20, -50);
    glVertex3f(35, -20, -10);
    glVertex3f(35, 20, -10);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(14.9, 0.8, 0.5);
    glVertex3f(40, 20, -50);
    glVertex3f(40, -20, -50);
    glVertex3f(40, -20, -10);
    glVertex3f(40, 20, -10);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(35, 20, -50);
    glVertex3f(35, 20, -10);
    glVertex3f(40, 20, -10);
    glVertex3f(40, 20, -50);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex3f(35, -20, -10);
    glVertex3f(35, -20, -50);
    glVertex3f(40, -20, -50);
    glVertex3f(40, -20, -10);
    glEnd();
}

void bangunankotaksampingkiri() {
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-35, 20, -50);
    glVertex3f(-35, -20, -50);
    glVertex3f(-35, -20, -10);
    glVertex3f(-35, 20, -10);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(1.9, 0.8, 0.5);
    glVertex3f(-40, 20, -50);
    glVertex3f(-40, -20, -50);
    glVertex3f(-40, -20, -10);
    glVertex3f(-40, 20, -10);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-35, 20, -50);
    glVertex3f(-35, 20, -10);
    glVertex3f(-40, 20, -10);
    glVertex3f(-40, 20, -50);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex3f(-40, -20, -10);
    glVertex3f(-40, -20, -50);
    glVertex3f(-35, -20, -50);
    glVertex3f(-35, -20, -10);
    glEnd();
}

void atapdepan() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-60, 20, 20);
    glVertex3f(-60, 40, 5);
    glVertex3f(60, 40, 5);
    glVertex3f(60, 20, 20);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-60, 20, -10);
    glVertex3f(-60, 40, 5);
    glVertex3f(60, 40, 5);
    glVertex3f(60, 20, -10);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 20, 20);
    glVertex3f(-60, 40, 5);
    glVertex3f(-60, 20, -10);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(60, 20, 20);
    glVertex3f(60, 40, 5);
    glVertex3f(60, 20, -10);
    glEnd();
}

void atapbelakang() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-60, 20, -50);
    glVertex3f(-60, 40, -65);
    glVertex3f(60, 40, -65);
    glVertex3f(60, 20, -50);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-60, 20, -80);
    glVertex3f(-60, 40, -65);
    glVertex3f(60, 40, -65);
    glVertex3f(60, 20, -80);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(-60, 20, -50);//kanan
    glVertex3f(-60, 40, -65);//tengah
    glVertex3f(-60, 20, -80);//kiri
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.8, 0.5);
    glVertex3f(60, 20, -50);
    glVertex3f(60, 40, -65);
    glVertex3f(60, 20, -80);
    glEnd();
}

void atapsampingkiri() {
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-35, 20, -50); //kiri bawah
    glVertex3f(-40, 40, -65); //kiri atas
    glVertex3f(-40, 40, 5); //kanan atas
    glVertex3f(-35, 20, -10); //kanan bawah
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-50, 20, -50); //kiri bawah
    glVertex3f(-40, 40, -65); //kiri atas
    glVertex3f(-40, 40, 5); //kanan atas
    glVertex3f(-50, 20, -10); //kanan bawah
    glEnd();
}

void atapsampingkanan() {
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(35, 20, -50);
    glVertex3f(40, 40, -65);
    glVertex3f(40, 40, 5);
    glVertex3f(35, 20, -10);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(50, 20, -50); //kiri bawah
    glVertex3f(40, 40, -65); //kiri atas
    glVertex3f(40, 40, 5); //kanan atas
    glVertex3f(50, 20, -10); //kanan bawah
    glEnd();
}

void atap_tengah() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(-20, 20, 20);
    glVertex3f(0, 40, 20);
    glVertex3f(20, 20, 20);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-20, 20, 20);
    glVertex3f(-5, 40, 5);
    glVertex3f(0, 40, 20);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(20, 20, 20);
    glVertex3f(5, 40, 5);
    glVertex3f(0, 40, 20);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-5, 40, 5);
    glVertex3f(0, 40, 20);
    glVertex3f(5, 40, 5);
    glEnd();
}

void tongsampah() {
    //alaskiri
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.855f, 0.055f);
    glVertex3f(48, -20, -10);
    glVertex3f(35, -20, -10);
    glVertex3f(35, -20, -50);
    glVertex3f(48, -20, -50);
    glEnd();
    //alaskanan
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.855f, 0.055f);
    glVertex3f(-48, -20, -10);
    glVertex3f(-35, -20, -10);
    glVertex3f(-35, -20, -50);
    glVertex3f(-48, -20, -50);
    glEnd();
    //tongbesar1
        //alas
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 1);
    glVertex3f(65, -20, -85);
    glVertex3f(65, -20, 50);
    glVertex3f(65, -20, -85);
    glVertex3f(65, -20, 50);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.533, 1);
    glVertex3f(47, -20, -10.56);
    glVertex3f(47, -20, -18.56);
    glVertex3f(47, -15, -18.56);
    glVertex3f(47, -15, -10.56);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.533, 1);
    glVertex3f(44, -20, -10.56);
    glVertex3f(44, -20, -18.56);
    glVertex3f(44, -15, -18.56);
    glVertex3f(44, -15, -10.56);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.125, 0.125, 0.125);
    glVertex3f(44, -15, -10.56);
    glVertex3f(44, -15, -18.56);
    glVertex3f(47, -15, -18.56);
    glVertex3f(47, -15, -10.56);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.533, 1);
    glVertex3f(44, -19, -10.56);
    glVertex3f(44, -19, -18.56);
    glVertex3f(47, -19, -18.56);
    glVertex3f(47, -19, -10.56);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.533, 1);
    glVertex3f(47, -15, -10.56);
    glVertex3f(44, -15, -10.56);
    glVertex3f(44, -19, -10.56);
    glVertex3f(47, -19, -10.56);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.533, 1);
    glVertex3f(47, -15, -18.56);
    glVertex3f(47, -19, -18.56);
    glVertex3f(44, -19, -18.56);
    glVertex3f(44, -15, -18.56);
    glEnd();
    //tongbesar2
    //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.231, 0.251, 0.271);
    glVertex3f(47, -19, -19.56);
    glVertex3f(44, -19, -19.56);
    glVertex3f(44, -19, -26.56);
    glVertex3f(47, -19, -26.56);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.525, 0.89);
    glVertex3f(44, -15, -19.56);
    glVertex3f(47, -15, -19.56);
    glVertex3f(47, -15, -26.56);
    glVertex3f(44, -15, -26.56);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.231, 0.251, 0.271);
    glVertex3f(47, -15, -19.56);
    glVertex3f(47, -19, -19.56);
    glVertex3f(47, -19, -26.56);
    glVertex3f(47, -15, -26.56);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.231, 0.251, 0.271);
    glVertex3f(44, -15, -19.56);
    glVertex3f(44, -19, -19.56);
    glVertex3f(44, -19, -26.56);
    glVertex3f(44, -15, -26.56);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.231, 0.251, 0.271);
    glVertex3f(44, -15, -19.56);
    glVertex3f(44, -19, -19.56);
    glVertex3f(47, -19, -19.56);
    glVertex3f(47, -15, -19.56);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.533, 1);
    glVertex3f(44, -15, -26.56);
    glVertex3f(44, -19, -26.56);
    glVertex3f(47, -19, -26.56);
    glVertex3f(47, -15, -26.56);
    glEnd();
    //tongkecil1
        //bawah
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(40, -19, -20.56);
    glVertex3f(40, -19, -18);
    glVertex3f(42, -19, -18);
    glVertex3f(42, -19, -20.56);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0.063);
    glVertex3f(40, -15, -20.56);
    glVertex3f(40, -15, -18);
    glVertex3f(42, -15, -18);
    glVertex3f(42, -15, -20.56);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(42, -15, -18);
    glVertex3f(40, -15, -18);
    glVertex3f(40, -19, -18);
    glVertex3f(42, -19, -18);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(42, -15, -20.56);
    glVertex3f(40, -15, -20.56);
    glVertex3f(40, -19, -20.56);
    glVertex3f(42, -19, -20.56);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(42, -15, -18);
    glVertex3f(42, -15, -20.56);
    glVertex3f(42, -19, -20.56);
    glVertex3f(42, -19, -18);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(40, -15, -18);
    glVertex3f(40, -15, -20.56);
    glVertex3f(42, -19, -20.56);
    glVertex3f(42, -19, -18);
    glEnd();
    //tongkecil2
        //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(40, -19, -22);
    glVertex3f(42, -19, -22);
    glVertex3f(42, -19, -24);
    glVertex3f(40, -19, -24);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.537, 0.914);
    glVertex3f(40, -15, -22);
    glVertex3f(42, -15, -22);
    glVertex3f(42, -15, -24);
    glVertex3f(40, -15, -24);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(42, -15, -22);
    glVertex3f(42, -19, -22);
    glVertex3f(42, -19, -24);
    glVertex3f(42, -15, -24);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(40, -15, -22);
    glVertex3f(40, -19, -22);
    glVertex3f(40, -19, -24);
    glVertex3f(40, -15, -24);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(40, -15, -22);
    glVertex3f(42, -15, -22);
    glVertex3f(42, -19, -22);
    glVertex3f(40, -19, -22);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(40, -15, -24);
    glVertex3f(42, -15, -24);
    glVertex3f(42, -19, -24);
    glVertex3f(40, -19, -24);
    glEnd();
    //tongkecil3
        //bawah
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(40, -19, -26);
    glVertex3f(40, -19, -28);
    glVertex3f(42, -19, -28);
    glVertex3f(42, -19, -26);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(40, -15, -26);
    glVertex3f(40, -19, -26);
    glVertex3f(42, -19, -26);
    glVertex3f(42, -15, -26);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(42, -15, -26);
    glVertex3f(42, -19, -26);
    glVertex3f(42, -19, -28);
    glVertex3f(42, -15, -28);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(40, -15, -26);
    glVertex3f(40, -19, -26);
    glVertex3f(40, -19, -28);
    glVertex3f(40, -15, -28);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.047, 0.537, 0.914);
    glVertex3f(40, -15, -26);
    glVertex3f(42, -15, -26);
    glVertex3f(42, -15, -28);
    glVertex3f(40, -15, -28);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.027, 0.239, 0.769);
    glVertex3f(40, -15, -28);
    glVertex3f(42, -15, -28);
    glVertex3f(42, -19, -28);
    glVertex3f(40, -19, -28);
    glEnd();
    //pintu
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.212, 0);
    glVertex3f(41, -19, -29);
    glVertex3f(41, -5, -29);
    glVertex3f(41, -5, -40);
    glVertex3f(41, -19, -40);
    glEnd();
    //corakbawah
    glBegin(GL_POLYGON);
    glColor3f(0.686, 0.686, 0.686);
    glVertex3f(41.01, -19, -29);
    glVertex3f(41.01, -19, -40);
    glVertex3f(41.01, -17, -40);
    glVertex3f(41.01, -17, -29);
    glEnd();
    //tengah
    glBegin(GL_LINES);
    glLineWidth(4);
    glColor3f(1, 1, 0);
    glVertex2i(41.02, -19);
    glVertex2i(41.02, -19);
    glEnd();
}
void cerobong1() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(-29.49, 36.52, 7.74); //kiri bawah
    glVertex3f(-24.49, 36.52, 7.74); //kiri atas
    glVertex3f(-24.49, 45.52, 7.74); //kanan atas
    glVertex3f(-29.49, 45.52, 7.74); //kanan bawah
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(-29.49, 36.52, 2.74);
    glVertex3f(-24.49, 36.52, 2.74);
    glVertex3f(-24.49, 45.52, 2.74);
    glVertex3f(-29.49, 45.52, 2.74);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(-29.49, 36.52, 2.74); //kiri bawah
    glVertex3f(-29.49, 45.52, 2.74); //kiri atas
    glVertex3f(-29.49, 45.52, 7.74); //kanan atas
    glVertex3f(-29.49, 36.52, 7.74); //kanan bawah
    glVertex3f(-29.49, 40.00, 2.74); //tengah
    glVertex3f(-29.49, 36.52, 2.74); //kiri bawah
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(-24.49, 36.52, 2.74); //kiri bawah
    glVertex3f(-24.49, 45.52, 2.74); //kiri atas
    glVertex3f(-24.49, 45.52, 7.74); //kanan atas
    glVertex3f(-24.49, 36.52, 7.74); //kanan bawah
    glVertex3f(-24.46, 40.00, 2.74); //tengah
    glVertex3f(-24.49, 36.52, 2.74); //kiri bawah
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(-29.49, 45.52, 2.74); //kiri bawah
    glVertex3f(-24.49, 45.52, 2.74); //kiri atas
    glVertex3f(-24.49, 45.52, 7.74); //kanan atas
    glVertex3f(-29.49, 45.52, 7.74); //kanan bawah
    glEnd();
}

void cerobong2() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(23.49, 36.52, 7.74); //kiri bawah
    glVertex3f(23.49, 45.52, 7.74); //kiri atas
    glVertex3f(27.49, 45.52, 7.74); //kanan atas
    glVertex3f(27.49, 36.52, 7.74); //kanan bawah
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(23.49, 36.52, 2.74);
    glVertex3f(23.49, 45.52, 2.74);
    glVertex3f(27.49, 45.52, 2.74);
    glVertex3f(27.49, 36.52, 2.74);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(23.49, 36.52, 2.74); //kiri bawah
    glVertex3f(23.49, 45.52, 2.74); //kiri atas
    glVertex3f(23.49, 45.52, 7.74); //kanan atas
    glVertex3f(23.49, 36.52, 7.74); //kanan bawah
    glVertex3f(23.49, 40.00, 2.74); //tengah
    glVertex3f(23.49, 36.52, 2.74); //kiri bawah
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(27.49, 36.52, 2.74); //kiri bawah
    glVertex3f(27.49, 45.52, 2.74); //kiri atas
    glVertex3f(27.49, 45.52, 7.74); //kanan atas
    glVertex3f(27.49, 36.52, 7.74); //kanan bawah
    glVertex3f(27.46, 40.00, 2.74); //tengah
    glVertex3f(27.49, 36.52, 2.74); //kiri bawah
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.3f, 1.4f);
    glVertex3f(23.49, 45.52, 2.74); //kiri bawah
    glVertex3f(27.49, 45.52, 2.74); //kiri atas
    glVertex3f(27.49, 45.52, 7.74); //kanan atas
    glVertex3f(23.49, 45.52, 7.74); //kanan bawah
    glEnd();
}

void jendela_depan_luar(float x) {

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-48.5 + x, 3, 20);
    glVertex3f(-48.5 + x, 17, 20);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-51.5 + x, 3, 20);
    glVertex3f(-51.5 + x, 17, 20);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-54 + x, 10, 20);
    glVertex3f(-46 + x, 10, 20);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-54 + x, 13.5, 20);
    glVertex3f(-46 + x, 13.5, 20);
    glEnd();

    //kaca
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.6, 0.6);
    glVertex3f(-54 + x, 3, 20);
    glVertex3f(-46 + x, 3, 20);
    glVertex3f(-46 + x, 17, 20);
    glVertex3f(-54 + x, 17, 20);
    glEnd();
}

void jendela_depan_dalam(float x) {

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-28.5 + x, 3, -10);
    glVertex3f(-28.5 + x, 17, -10);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-31.5 + x, 3, -10);
    glVertex3f(-31.5 + x, 17, -10);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-34 + x, 10, -10);
    glVertex3f(-26 + x, 10, -10);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-34 + x, 13.5, -10);
    glVertex3f(-26 + x, 13.5, -10);
    glEnd();

    //kaca
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.6, 0.6);
    glVertex3f(-34 + x, 3, -10);
    glVertex3f(-26 + x, 3, -10);
    glVertex3f(-26 + x, 17, -10);
    glVertex3f(-34 + x, 17, -10);
    glEnd();
}

void jendela_belakang_luar(float x) {

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-48.5 + x, 3, -80);
    glVertex3f(-48.5 + x, 17, -80);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-51.5 + x, 3, -80);
    glVertex3f(-51.5 + x, 17, -80);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-54 + x, 10, -80);
    glVertex3f(-46 + x, 10, -80);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-54 + x, 13.5, -80);
    glVertex3f(-46 + x, 13.5, -80);
    glEnd();

    //kaca
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.6, 0.6);
    glVertex3f(-54 + x, 3, -80);
    glVertex3f(-46 + x, 3, -80);
    glVertex3f(-46 + x, 17, -80);
    glVertex3f(-54 + x, 17, -80);
    glEnd();
}

void jendela_belakang_dalam(float x) {

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-28.5 + x, 3, -50);
    glVertex3f(-28.5 + x, 17, -50);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-31.5 + x, 3, -50);
    glVertex3f(-31.5 + x, 17, -50);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-34 + x, 10, -50);
    glVertex3f(-26 + x, 10, -50);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-34 + x, 13.5, -50);
    glVertex3f(-26 + x, 13.5, -50);
    glEnd();

    //kaca
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.6, 0.6);
    glVertex3f(-34 + x, 3, -50);
    glVertex3f(-26 + x, 3, -50);
    glVertex3f(-26 + x, 17, -50);
    glVertex3f(-34 + x, 17, -50);
    glEnd();
}

void jendela_kanan_luar(float x, float z) {

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(40 + x, 3, 7.5 - z);
    glVertex3f(40 + x, 17, 7.5  - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(40 + x, 3, 10.5 - z);
    glVertex3f(40 + x, 17, 10.5 - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(40 + x, 10, 5 - z);
    glVertex3f(40 + x, 10, 13 - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(40 + x, 13.5, 5 - z);
    glVertex3f(40 + x, 13.5, 13 - z);
    glEnd();

    //kaca
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.6, 0.6);
    glVertex3f(40 + x, 3, 5 - z);
    glVertex3f(40 + x, 3, 13 - z);
    glVertex3f(40 + x, 17, 13 - z);
    glVertex3f(40 + x, 17, 5 - z);
    glEnd();
}

void jendela_kanan_dalam(float z) {

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(35, 3, 7.5 - z);
    glVertex3f(35, 17, 7.5  - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(35, 3, 10.5 - z);
    glVertex3f(35, 17, 10.5 - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(35, 10, 5 - z);
    glVertex3f(35, 10, 13 - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(35, 13.5, 5 - z);
    glVertex3f(35, 13.5, 13 - z);
    glEnd();

    //kaca
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.6, 0.6);
    glVertex3f(35, 3, 5 - z);
    glVertex3f(35, 3, 13 - z);
    glVertex3f(35, 17, 13 - z);
    glVertex3f(35, 17, 5 - z);
    glEnd();
}

void jendela_kiri_luar(float x, float z) {

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-40 - x, 3, 7.5 - z);
    glVertex3f(-40 - x, 17, 7.5  - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-40 - x, 3, 10.5 - z);
    glVertex3f(-40 - x, 17, 10.5 - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-40 - x, 10, 5 - z);
    glVertex3f(-40 - x, 10, 13 - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-40 - x, 13.5, 5 - z);
    glVertex3f(-40 - x, 13.5, 13 - z);
    glEnd();

    //kaca
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.6, 0.6);
    glVertex3f(-40 - x, 3, 5 - z);
    glVertex3f(-40 - x, 3, 13 - z);
    glVertex3f(-40 - x, 17, 13 - z);
    glVertex3f(-40 - x, 17, 5 - z);
    glEnd();
}

void jendela_kiri_dalam(float z) {

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-35, 3, 7.5 - z);
    glVertex3f(-35, 17, 7.5  - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-35, 3, 10.5 - z);
    glVertex3f(-35, 17, 10.5 - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-35, 10, 5 - z);
    glVertex3f(-35, 10, 13 - z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex3f(-35, 13.5, 5 - z);
    glVertex3f(-35, 13.5, 13 - z);
    glEnd();

    //kaca
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.6, 0.6);
    glVertex3f(-35, 3, 5 - z);
    glVertex3f(-35, 3, 13 - z);
    glVertex3f(-35, 17, 13 - z);
    glVertex3f(-35, 17, 5 - z);
    glEnd();
}

void tampil_perulangan() {
    for (int i = 0; i < 8; i++) {
        jendela_depan_luar(i * 14.25);
    }
    for (int i = 0; i < 5; i++) {
        jendela_depan_dalam(i * 14.25);
    }
    for (int i = 0; i < 8; i++) {
        jendela_belakang_luar(i * 14.25);
    }
    for (int i = 0; i < 5; i++) {
        jendela_belakang_dalam(i * 14.25);
    }
    for(int i = 0; i < 9; i++){
        if(i==0){
            jendela_kanan_luar(i + 20, i - 2);
        }else if(i==1){
            jendela_kanan_luar(i + 19, i + 9);
        }else if(i==7){
            jendela_kanan_luar(i + 13, i + 61);
        }else if(i==8){
            jendela_kanan_luar(i + 12, i + 72);
        }else{
            jendela_kanan_luar(0, i * 13);
        }
    }
    for (int i = 0; i < 5; i++) {
        jendela_kanan_dalam(i * 13);
    }
    for(int i = 0; i < 9; i++){
        if(i==0){
            jendela_kiri_luar(i + 20, i - 2);
        }else if(i==1){
            jendela_kiri_luar(i + 19, i + 9);
        }else if(i==7){
            jendela_kiri_luar(i + 13, i + 61);
        }else if(i==8){
            jendela_kiri_luar(i + 12, i + 72);
        }else{
            jendela_kiri_luar(0, i * 13);
        }
    }
    for (int i = 0; i < 5; i++) {
        jendela_kiri_dalam(i * 13);
    }
    for (int i = 0; i < 9; i++) {
        pilar_depan(i * 14.25);
    }
    for (int i = 0; i < 9; i++) {
        pilar_belakang(i * 14.25);
    }
    for (int i = 0; i < 3; i++) {
        pilar_depankiri(i * 12);
    }
    for (int i = 0; i < 3; i++) {
        pilar_depankanan(i * 12);
    }
    for (int i = 0; i < 3; i++) {
        pilar_belakangkiri(i * 12);
    }
    for (int i = 0; i < 3; i++) {
        pilar_belakangkanan(i * 12);
    }
}

void papan_tulis() {
    //depan
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-10, -10, -5);
    glVertex3f(-10, 0, -5);
    glVertex3f(10, 0, -5);
    glVertex3f(10, -10, -5);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-10, -10, -7);
    glVertex3f(-10, 0, -7);
    glVertex3f(10, 0, -7);
    glVertex3f(10, -10, -7);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-10, -10, -5);
    glVertex3f(-10, 0, -5);
    glVertex3f(-10, 0, -7);
    glVertex3f(-10, -10, -7);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(10, -10, -5);
    glVertex3f(10, 0, -5);
    glVertex3f(10, 0, -7);
    glVertex3f(10, -10, -7);
    glEnd();
}

void meja(){
    //atas
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-12, -12, -7);
    glVertex3f(-12, -12, -12);
    glVertex3f( 0, -12, -12);
    glVertex3f( 0, -12, -7);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-12, -14, -7);
    glVertex3f(-12, -14, -12);
    glVertex3f( 0, -14, -12);
    glVertex3f( 0, -14, -7);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-12, -14, -12);
    glVertex3f(-12, -12, -12);
    glVertex3f( 0, -12, -12);
    glVertex3f( 0, -14, -12);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.0f, 1.0f);
    glVertex3f(-12, -14, -7);
    glVertex3f(-12, -12, -7);
    glVertex3f(-12, -12, -12);
    glVertex3f(-12, -14, -12);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.0f, 1.0f);
    glVertex3f( 0, -14, -7);
    glVertex3f( 0, -12, -7);
    glVertex3f( 0, -12, -12);
    glVertex3f( 0, -14, -12);
    glEnd();

    //kaki
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( -7, -14, -8.5);
    glVertex3f( -7, -14, -11.5);
    glVertex3f( -7, -18, -11.5);
    glVertex3f( -7, -18, -8.5);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( -5, -14, -8.5);
    glVertex3f( -5, -14, -11.5);
    glVertex3f( -5, -18, -11.5);
    glVertex3f( -5, -18, -8.5);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( -7, -14, -11.5);
    glVertex3f( -5, -14, -11.5);
    glVertex3f( -5, -18, -11.5);
    glVertex3f( -7, -18, -11.5);
    glEnd();

    //depan
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( -7, -14, -8.5);
    glVertex3f( -5, -14, -8.5);
    glVertex3f( -5, -18, -8.5);
    glVertex3f( -7, -18, -8.5);
    glEnd();
}

void kursi(){
    //atas
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( 2, -15, -5);
    glVertex3f( 2, -15, -2);
    glVertex3f( 5, -15, -2);
    glVertex3f( 5, -15, -5);
    glEnd();

    //kaki
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( 3, -15, -4);
    glVertex3f( 3, -15, -2);
    glVertex3f( 3, -18, -2);
    glVertex3f( 3, -18, -4);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( 4, -15, -4);
    glVertex3f( 4, -15, -2);
    glVertex3f( 4, -18, -2);
    glVertex3f( 4, -18, -4);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f( 3, -15, -4);
    glVertex3f( 4, -15, -4);
    glVertex3f( 4, -18, -4);
    glVertex3f( 3, -18, -4);
    glEnd();

    //depan
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f( 3, -15, -2);
    glVertex3f( 4, -15, -2);
    glVertex3f( 4, -18, -2);
    glVertex3f( 3, -18, -2);
    glEnd();
}

void loker(){
    //atas
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f( 6, 0, -2);
    glVertex3f( 10, 0, -6);
    glVertex3f( 10, 0, -6);
    glVertex3f( 6, 0, -2);

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f( 6, -18, -2);
    glVertex3f( 10, -18, -6);
    glVertex3f( 10, -18, -6);
    glVertex3f( 6, -18, -2);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f( 6, 0, -2);
    glVertex3f( 6, 0, -6);
    glVertex3f( 6, -18, -6);
    glVertex3f( 6, -18, -2);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f( 10, 0, -2);
    glVertex3f( 10, 0, -6);
    glVertex3f( 10, -18, -6);
    glVertex3f( 10, -18, -2);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f( 6, 0, -6);
    glVertex3f( 10, 0, -6);
    glVertex3f( 10, -18, -6);
    glVertex3f( 6, -18, -6);
    glEnd();

    //depan
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 6, 0, -2);
    glVertex3f( 10, 0, 0);
    glVertex3f( 10, -18, 0);
    glVertex3f( 6, -18, -2);
    glEnd();
}

void pagar1(float x, float y, float z){
    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50 + x, -14.5 + y, -10 - z);
    glVertex3f(50 + x, 2 + y, -10 - z);
    glVertex3f(50 + x, 2 + y, -10.5 - z);
    glVertex3f(50 + x, -14.5 + y, -10.5 - z);
    glEnd();
}

void pagar2(float x, float y, float z){
    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50 + x, -20 + y, -27 - z);
    glVertex3f(50 + x, 5 + y, -27 - z);
    glVertex3f(50 + x, 5 + y, -27.5 - z);
    glVertex3f(50 + x, -20 + y, -27.5 - z);
    glEnd();
}

void pagar3(float x, float y, float z){
    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50 + x, -14.5 + y, -39.5 - z);
    glVertex3f(50 + x, 2 + y, -39.5 - z);
    glVertex3f(50 + x, 2 + y, -40 - z);
    glVertex3f(50 + x, -14.5 + y, -40 - z);
    glEnd();
}

void pagar4(float x, float y, float z){
    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(-50 + x, -14.5 + y, -10 - z);
    glVertex3f(-50 + x, 2 + y, -10 - z);
    glVertex3f(-50 + x, 2 + y, -10.5 - z);
    glVertex3f(-50 + x, -14.5 + y, -10.5 - z);
    glEnd();
}

void pagar(){
    //PAGAR SISI KANAN
    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, 1, -10);
    glVertex3f(50, 0.5, -10);
    glVertex3f(50, 0.5, -27);
    glVertex3f(50, 1, -27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -1, -10);
    glVertex3f(50, -0.5, -10);
    glVertex3f(50, -0.5, -27);
    glVertex3f(50, -1, -27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, 1, -10);
    glVertex3f(50, 0.5, -10);
    glVertex3f(50, 0.5, -27);
    glVertex3f(50, 1, -27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -12.5, -10);
    glVertex3f(50, -12, -10);
    glVertex3f(50, -12, -27);
    glVertex3f(50, -12.5, -27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -8.5, -10);
    glVertex3f(50, -8, -10);
    glVertex3f(50, -8, -27);
    glVertex3f(50, -8.5, -27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -14, -10);
    glVertex3f(50, -13.5, -10);
    glVertex3f(50, -13.5, -27);
    glVertex3f(50, -14, -27);
    glEnd();

    //bata atas sisi depan
    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, .6f);
    glVertex3f(50, -17, -10);
    glVertex3f(50, -14.5, -10);
    glVertex3f(50, -14.5, -27);
    glVertex3f(50, -17, -27);
    glEnd();

    //bata atas sisi belakang
    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, .6f);
    glVertex3f(48, -17, -10);
    glVertex3f(48, -14.5, -10);
    glVertex3f(48, -14.5, -27);
    glVertex3f(48, -17, -27);
    glEnd();

    //bata atas sisi kanan
    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, .6f);
    glVertex3f(50, -17, -25);
    glVertex3f(48, -17, -25);
    glVertex3f(48, -14.5, -27);
    glVertex3f(50, -14.5, -27);
    glEnd();

    //bata paling bawah sisi depan
    glBegin(GL_POLYGON);
    glColor3f(.8f, .8f, .8f);
    glVertex3f(50, -20, -10);
    glVertex3f(50, -17, -10);
    glVertex3f(50, -17, -27);
    glVertex3f(50, -20, -27);
    glEnd();

    //bata paling bawah sisi belakang
    glBegin(GL_POLYGON);
    glColor3f(.8f, .8f, .8f);
    glVertex3f(48, -20, -10);
    glVertex3f(48, -17, -10);
    glVertex3f(48, -17, -27);
    glVertex3f(48, -20, -27);
    glEnd();

    //bata paling bawah sisi kanan
    glBegin(GL_POLYGON);
    glColor3f(.8f, .8f, .8f);
    glVertex3f(50, -20, -27);
    glVertex3f(48, -20, -27);
    glVertex3f(48, -17, -27);
    glVertex3f(50, -17, -27);
    glEnd();

    //pintu pagar
    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -20, -27);
    glVertex3f(50, -11, -27);
    glVertex3f(50, -11, -40);
    glVertex3f(50, -20, -40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -10, -27);
    glVertex3f(50, -9.5, -27);
    glVertex3f(50, -9.5, -40);
    glVertex3f(50, -10, -40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -8, -27);
    glVertex3f(50, -7.5, -27);
    glVertex3f(50, -7.5, -40);
    glVertex3f(50, -8, -40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -3, -27);
    glVertex3f(50, -2.5, -27);
    glVertex3f(50, -2.5, -40);
    glVertex3f(50, -3, -40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, 4, -27);
    glVertex3f(50, 3.5, -27);
    glVertex3f(50, 3.5, -40);
    glVertex3f(50, 4, -40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, 3, -27);
    glVertex3f(50, 2.5, -27);
    glVertex3f(50, 2.5, -40);
    glVertex3f(50, 3, -40);
    glEnd();

    //bata2 atas sisi depan
    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, .6f);
    glVertex3f(50, -17, -40);
    glVertex3f(50, -14.5, -40);
    glVertex3f(50, -14.5, -55);
    glVertex3f(50, -17, -55);
    glEnd();

    //bat2a atas sisi belakang
    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, .6f);
    glVertex3f(48, -17, -40);
    glVertex3f(48, -14.5, -40);
    glVertex3f(48, -14.5, -55);
    glVertex3f(48, -17, -55);
    glEnd();

    //bata2 atas sisi kiri
    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, .6f);
    glVertex3f(50, -17, -40);
    glVertex3f(48, -17, -40);
    glVertex3f(48, -14.5, -40);
    glVertex3f(50, -14.5, -40);
    glEnd();

    //bata paling bawah sisi depan
    glBegin(GL_POLYGON);
    glColor3f(.8f, .8f, .8f);
    glVertex3f(50, -20, -40);
    glVertex3f(50, -17, -40);
    glVertex3f(50, -17, -55);
    glVertex3f(50, -20, -55);
    glEnd();

    //bata paling bawah sisi belakang
    glBegin(GL_POLYGON);
    glColor3f(.8f, .8f, .8f);
    glVertex3f(48, -20, -40);
    glVertex3f(48, -17, -40);
    glVertex3f(48, -17, -50);
    glVertex3f(48, -20, -50);
    glEnd();

    //bata paling bawah sisi kanan
    glBegin(GL_POLYGON);
    glColor3f(.8f, .8f, .8f);
    glVertex3f(50, -20, -55);
    glVertex3f(48, -20, -55);
    glVertex3f(48, -17, -55);
    glVertex3f(50, -17, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, 1, -40);
    glVertex3f(50, 0.5, -40);
    glVertex3f(50, 0.5, -55);
    glVertex3f(50, 1, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -1, -40);
    glVertex3f(50, -0.5, -40);
    glVertex3f(50, -0.5, -55);
    glVertex3f(50, -1, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, 1, -40);
    glVertex3f(50, 0.5, -40);
    glVertex3f(50, 0.5, -50);
    glVertex3f(50, 1, -50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -12.5, -40);
    glVertex3f(50, -12, -40);
    glVertex3f(50, -12, -55);
    glVertex3f(50, -12.5, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -8.5, -40);
    glVertex3f(50, -8, -40);
    glVertex3f(50, -8, -55);
    glVertex3f(50, -8.5, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(50, -14, -40);
    glVertex3f(50, -13.5, -40);
    glVertex3f(50, -13.5, -55);
    glVertex3f(50, -14, -55);
    glEnd();

    for (int i = 0; i < 5; i++)
    {
        pagar1(0, 0, i * 3.8);
    }

    for (int i = 0; i < 6; i++)
    {
        pagar2(0, 0, i * 2.5);
    }

    for (int i = 0; i < 3; i++)
    {
        pagar3(0, 0, i * 3.8);
    }

    //PAGAR SISI KIRI
    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(-50, 1, -10);
    glVertex3f(-50, 0.5, -10);
    glVertex3f(-50, 0.5, -55);
    glVertex3f(-50, 1, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(-50, -1, -10);
    glVertex3f(-50, -0.5, -10);
    glVertex3f(-50, -0.5, -55);
    glVertex3f(-50, -1, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(-50, 1, -10);
    glVertex3f(-50, 0.5, -10);
    glVertex3f(-50, 0.5, -55);
    glVertex3f(-50, 1, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(-50, -12.5, -10);
    glVertex3f(-50, -12, -10);
    glVertex3f(-50, -12, -55);
    glVertex3f(-50, -12.5, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(-50, -8.5, -10);
    glVertex3f(-50, -8, -10);
    glVertex3f(-50, -8, -55);
    glVertex3f(-50, -8.5, -55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0f, .0f, .0f);
    glVertex3f(-50, -14, -10);
    glVertex3f(-50, -13.5, -10);
    glVertex3f(-50, -13.5, -55);
    glVertex3f(-50, -14, -55);
    glEnd();

    //bata atas sisi depan
    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, .6f);
    glVertex3f(-50, -17, -10);
    glVertex3f(-50, -14.5, -10);
    glVertex3f(-50, -14.5, -55);
    glVertex3f(-50, -17, -55);
    glEnd();

    //bata atas sisi belakang
    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, .6f);
    glVertex3f(-48, -17, -10);
    glVertex3f(-48, -14.5, -10);
    glVertex3f(-48, -14.5, -55);
    glVertex3f(-48, -17, -55);
    glEnd();

    //bata atas sisi kanan
    glBegin(GL_POLYGON);
    glColor3f(.6f, .6f, .6f);
    glVertex3f(-50, -17, -53);
    glVertex3f(-48, -17, -53);
    glVertex3f(-48, -14.5, -55);
    glVertex3f(-50, -14.5, -55);
    glEnd();

    //bata paling bawah sisi depan
    glBegin(GL_POLYGON);
    glColor3f(.8f, .8f, .8f);
    glVertex3f(-50, -20, -10);
    glVertex3f(-50, -17, -10);
    glVertex3f(-50, -17, -55);
    glVertex3f(-50, -20, -55);
    glEnd();

    //bata paling bawah sisi belakang
    glBegin(GL_POLYGON);
    glColor3f(.8f, .8f, .8f);
    glVertex3f(-48, -20, -10);
    glVertex3f(-48, -17, -10);
    glVertex3f(-48, -17, -55);
    glVertex3f(-48, -20, -55);
    glEnd();

    //bata paling bawah sisi kanan
    glBegin(GL_POLYGON);
    glColor3f(.8f, .8f, .8f);
    glVertex3f(-50, -20, -55);
    glVertex3f(-48, -20, -55);
    glVertex3f(-48, -17, -55);
    glVertex3f(-50, -17, -55);
    glEnd();

    for (int i = 0; i < 116; i++)
    {
        pagar4(0, 0, i * 3.8);
    }
}

void tampil(void) {
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    };

    glPushMatrix();
    glTranslatef(c, 0, d);
    glScalef(x, y, z);
    tampil_perulangan();
    bangunankotakdepan();
    ataspilar_depan();
    ataspilar_depankirikanan();
    bangunankotakbelakang();
    ataspilar_belakang();
    ataspilar_belakangkirikanan();
    bangunankotaksampingkanan();
    bangunankotaksampingkiri();
    atap_menara();
    cerobong1();
    cerobong2();
    menara();
    atapdepan();
    atapbelakang();
    atapsampingkanan();
    atapsampingkiri();
    atap_tengah();
    papan_tulis();
    meja();
    kursi();
    pagar();
    loker();
    tongsampah();
    glPopMatrix();
    glFlush();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void mouse(int button, int state, int xmouse, int ymouse) {
    if (flg == 0) {
        if (state == GLUT_DOWN) {
            if (button == GLUT_LEFT_BUTTON) {
                flag++;
                if (flag == 2) {
                    flg = 3;
                    x = 3;
                    y = 3;
                    printf("%d", flg);
                }
            }
        }
    }
    if (flg == 3) {
        if (state == GLUT_DOWN) {
            if (button == GLUT_LEFT_BUTTON) {
                flag--;
                if (flag == 0) {
                    x = 1;
                    y = 1;
                    flg = 0;
                    printf("%d", flg);
                }
            }
        }
    }
}

void mySpecialKeyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT: c += -4; d += 0;
        break;
    case GLUT_KEY_RIGHT: c += 4; d += 0;
        break;
    case GLUT_KEY_UP: c += 0; d += 4;
        break;
    case GLUT_KEY_DOWN: c += 0; d += -4;
        break;
    }
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}

void ukuran(int lebar, int tinggi) {
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
