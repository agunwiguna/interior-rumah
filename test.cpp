#include <windows.h>  
#include <GL/glut.h>  
//#include <stdlib.h>  
  
  
static int slices = 25;  
static int stacks = 25;  
  
float ratio;                                        // Full-Screen Kamera  
float yCord = -2.5;                                 // Koordinat Y  
float zCord = -60.0;                                // Koordinat Z  
float RotateX = -30.0f;                             // Rotasi Kamera Kanan Kiri  
float RotationSpeedX = 0.0f;                        // Kecepatan Rotasi  
float RotasiKipas = 0.0f;  
float RotasiKipas2 = 0.0f;  
float KecRot = 0.0f;  
float KecRot2 = 0.0f;  
float LightZ = 26.0f;  
float LightX = 0.0f;  
float LightY = 15.0f;  
  
  
GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };  
GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };  
GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };  
GLfloat light_position[] = { LightX, LightY, LightZ, 0.0f };  
  
  
GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };  
GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };  
GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };  
GLfloat high_shininess[] = { 100.0f };  
  
  
void sumbu (void){  
    glColor3f(1.0, 0.0, 0.0);      
    glBegin(GL_LINES);  //=======================> Sumbu x (MERAH)  
        glVertex3f(-30.0, 0.0, 0.0); //titik kiri  
        glVertex3f(30.0, 0.0, 0.0); //titik kanan  
    glEnd();  
      
    glColor3f(0.0, 1.0, 0.0);     
    glBegin(GL_LINES);  //=======================> Sumbu y (HIJAU)  
        glVertex3f(0.0, 10, 0.0); //titik atas  
        glVertex3f(0.0, -10.0, 0.0); //titik bawah  
    glEnd();  
      
    glColor3f(0.0, 0.0, 1.0);      
    glBegin(GL_LINES);  //=======================> Sumbu z (BIRU)  
        glVertex3f(0.0, 0.0, -30.0); //titik belakang  
        glVertex3f(0.0, 0.0, 30.0); //titik depan  
    glEnd();       
}  
  
  
static void resize(int width, int height)  
{  
    const float ar = (float) width / (float) height;  
      
    glViewport(0, 0, width, height);  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);  
      
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity() ;  
}  
  
static void display(void)  
{  
    gluLookAt (1.0, 10.0, 15.0,  
                    0.0, 0.0, 5.0,   
                         0.0, 10.0, 0.0);                  
      
    const double t= glutGet(GLUT_ELAPSED_TIME) /10000.0;  
    const double t2= glutGet(GLUT_ELAPSED_TIME) /20.0;  
    const double a = t*90.0, b = t/2, c = t/10, d = t2*90;  
  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
    glLoadIdentity();  
    glTranslatef(0.0,yCord,zCord);  
    glTranslatef(0.0,yCord,0.0);  
    glRotatef(RotateX, 0, 1.0, 0);  
    RotasiKipas += KecRot;  
    RotasiKipas2 += KecRot2;  
    RotateX += RotationSpeedX;  
      
    glPushMatrix();  
        sumbu();  
    glPopMatrix();  
  
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX Bagian Kamar XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  
  
  
// Bagian Kamar ===================================================================================>  
      
    // Tembok ===========================================================================>  
      
    glPushMatrix();  // Tembok Hitam Sumbu X Kiri  ============================>  
        glTranslated(8.0,-1.0,0.2);  
        glScaled(16.0,5.0,0.5);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Putih Sumbu X Kiri  ============================>  
        glTranslated(8.0,2.0,0.2);  
        glScaled(16.0,1.0,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Merah Sumbu X Kiri  ============================>  
        glTranslated(8.0,6.0,0.2);  
        glScaled(16.0,7.0,0.5);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Hitam Sumbu X Kanan  ===========================>  
        glTranslated(23.5,-1.0,0.2);  
        glScaled(2.9,5.0,0.5);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Putih Sumbu X Kanan  ===========================>  
        glTranslated(23.5,2.0,0.2);  
        glScaled(2.9,1.0,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Merah Sumbu X Kanan  ===========================>  
        glTranslated(23.5,6.0,0.2);  
        glScaled(2.9,7.0,0.5);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Merah Sumbu X Atas  ============================>  
        glTranslated(19,9.0,0.2);  
        glScaled(6.1,1.0,0.5);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Hitam Sumbu Z Kanan  ===========================>  
        glTranslated(0.2,-1.0,6.0);  
        glScaled(0.5,5.0,12.0);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Putih Sumbu Z Kanan  ===========================>  
        glTranslated(0.2,2.0,6.0);  
        glScaled(0.5,1.0,12.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Merah Sumbu Z Kanan  ===========================>  
        glTranslated(0.2,6.0,6.0);  
        glScaled(0.5,7.0,12.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Hitam Sumbu Z Kiri  ============================>  
        glTranslated(0.2,-1.0,18.5);  
        glScaled(0.5,5.0,0.9);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Putih Sumbu Z Kiri  ============================>  
        glTranslated(0.2,2.0,18.5);  
        glScaled(0.5,1.0,0.9);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Merah Sumbu Z Kiri  ============================>  
        glTranslated(0.2,6.0,18.5);  
        glScaled(0.5,7.0,0.9);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Hitam Sumbu Z Kiri jendela =====================>  
        glTranslated(0.2,-1.0,24.5);  
        glScaled(0.5,5.0,1.0);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Putih Sumbu Z Kiri jendela  ====================>  
        glTranslated(0.2,2.0,24.5);  
        glScaled(0.5,1.0,0.9);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Merah Sumbu Z Kiri jendela  ====================>  
        glTranslated(0.2,6.0,24.5);  
        glScaled(0.5,7.0,0.9);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Hitam Sumbu Z Bawah ============================>  
        glTranslated(0.2,-1.7,21.5);  
        glScaled(0.5,3.0,5.2);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Tembok Merah Sumbu Z Atas  ============================>  
        glTranslated(0.2,9.0,15.0);  
        glScaled(0.5,1.0,6.1);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tembok Merah Sumbu Z Atas 2  ==========================>  
        glTranslated(0.2,9.0,21.0);  
        glScaled(0.5,1.0,6.1);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
  
    // Bingkai Pintu Kamar  =============================================================>  
      
    glPushMatrix();  // Bingkai Pintu Sumbu X Berdiri  ========================>  
        glTranslated(16.4,2.5,0.0);  
        glScaled(0.8,12.0,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Pintu Sumbu X Berdiri  ========================>  
        glTranslated(21.6,2.5,0.0);  
        glScaled(0.8,12.0,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Pintu Sumbu X Baring  =========================>  
        glTranslated(19.0,6.8,0.0);  
        glScaled(4.5,0.5,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Pintu Sumbu X Baring  =========================>  
        glTranslated(19.0,8.2,0.0);  
        glScaled(4.5,0.5,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Pintu Sumbu Z Berdiri  ========================>  
        glTranslated(0.0,2.5,12.4);  
        glScaled(0.5,12.0,0.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Pintu Sumbu Z Berdiri  ========================>  
        glTranslated(0.0,2.5,17.6);  
        glScaled(0.5,12.0,0.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Bingkai Pintu Sumbu Z Baring  =========================>  
        glTranslated(0.0,8.2,15.0);  
        glScaled(0.5,0.5,4.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Pintu Sumbu Z Baring  =========================>  
        glTranslated(0.0,6.8,15.0);  
        glScaled(0.5,0.5,4.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Bingkai Jendela Sumbu Z Berdiri  ======================>  
        glTranslated(0.0,4.1,19.4);  
        glScaled(0.5,8.7,0.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Jendela Sumbu Z Berdiri  ======================>  
        glTranslated(0.0,4.1,23.6);  
        glScaled(0.5,8.7,0.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Bingkai Jendela Sumbu Z Baring  =======================>  
        glTranslated(0.0,8.2,21.5);  
        glScaled(0.5,0.5,3.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Jendela Sumbu Z Baring  =======================>  
        glTranslated(0.0,6.8,21.5);  
        glScaled(0.5,0.5,3.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Jendela Sumbu Z Baring  =======================>  
        glTranslated(0.0,0.0,21.5);  
        glScaled(0.5,0.5,3.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
  
    // Pintu Kamar  =====================================================================>  
      
    glPushMatrix();  // Pintu 1 ===============================================>  
        glTranslated(19.0,1.5,0.0);  
        glScaled(4.5,10.0,0.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Textur 1 Dari Atas  ===========================>  
        glTranslated(19.0,5.0,0.0);  
        glScaled(3.0,1.0,1.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Textur 2 Dari Atas  ===========================>  
        glTranslated(19.0,3.0,0.0);  
        glScaled(3.0,1.0,1.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Pintu 1 Textur 3 Dari Atas  ===========================>    
        glTranslated(19.0,0.5,0.0);  
        glScaled(3.0,1.0,1.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Textur 4 Dari Atas  ===========================>  
        glTranslated(19.0,-1.5,0.0);  
        glScaled(3.0,1.0,1.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Textur Tengah  ================================>  
        glTranslated(19.0,1.75,0.0);  
        glScaled(2.0,0.5,1.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Pintu 1 As Pegangan ===================================>  
        glTranslated(17.45,1.75,0.0);  
        glScaled(0.3,0.3,1.0);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Lingkaran Pegangan ============================>  
        glTranslated(17.45,1.75,0.0);  
        glScaled(0.4,0.4,0.4);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Lingkaran Genggaman Dalam =====================>  
        glTranslated(17.45,1.75,0.65);  
        glScaled(0.3,0.3,0.2);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Lingkaran Genggaman Luar ======================>  
        glTranslated(17.45,1.75,-0.65);  
        glScaled(0.3,0.3,0.2);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Pintu 2 ===============================================>  
        glTranslated(2.4,1.5,16.5);  
        glRotated(-70,0,50,0);  
        glScaled(0.5,10.0,4.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Pintu 2 Textur 1 Dari Atas ============================>  
        glTranslated(2.4,5.0,16.5);  
        glRotated(-70,0,50,0);  
        glScaled(1.0,1.0,3.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 2 Textur 2 Dari Atas ============================>  
        glTranslated(2.4,3.0,16.5);  
        glRotated(-70,0,50,0);  
        glScaled(1.0,1.0,3.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 2 Textur 3 Dari Atas ============================>  
        glTranslated(2.4,0.5,16.5);  
        glRotated(-70,0,50,0);  
        glScaled(1.0,1.0,3.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 2 Textur 4 Dari Atas ============================>  
        glTranslated(2.4,-1.5,16.5);  
        glRotated(-70,0,50,0);  
        glScaled(1.0,1.0,3.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 2 Textur Tengah =================================>  
        glTranslated(2.4,1.75,16.5);  
        glRotated(-70,0,50,0);  
        glScaled(1.0,0.5,2.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 2 As Pegangan ===================================>  
        glTranslated(3.9,1.75,15.95);  
        glRotated(-70,0,50,0);  
        glScaled(1.0,0.3,0.3);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 2 Lingkaran Pegangan ============================>  
        glTranslated(3.9,1.75,15.95);  
        glRotated(-70,0,50,0);  
        glScaled(0.4,0.4,0.4);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 2 Lingkaran Genggaman Dalam =====================>  
        glTranslated(4.2,1.75,16.5);  
        glRotated(-70,0,50,0);  
        glScaled(0.2,0.3,0.3);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 2 Lingkaran Genggaman Luar ======================>  
        glTranslated(3.7,1.75,15.4);  
        glRotated(-70,0,50,0);  
        glScaled(0.2,0.3,0.3);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
  
    // Lantai  ==========================================================================>  
                       
    glPushMatrix();  // Ubin Dasar  ===========================================>  
        glTranslated(12.5,-3.5,12.5);  
        glScaled(25.0,0.5,25);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // baris 1 sejajar X      
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(2.1,-3.5,2.1);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(5.2,-3.5,2.1);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(8.3,-3.5,2.1);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(11.4,-3.5,2.1);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(14.5,-3.5,2.1);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(17.6,-3.5,2.1);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(20.7,-3.5,2.1);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(23.5,-3.5,2.1);  
        glScaled(2.5,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // baris 2 sejajar X  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(2.1,-3.5,5.2);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(5.2,-3.5,5.2);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(8.3,-3.5,5.2);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(11.4,-3.5,5.2);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(14.5,-3.5,5.2);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(17.6,-3.5,5.2);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(20.7,-3.5,5.2);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(23.5,-3.5,5.2);  
        glScaled(2.5,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // baris 3 sejajar X  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(2.1,-3.5,8.3);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(5.2,-3.5,8.3);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(8.3,-3.5,8.3);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(11.4,-3.5,8.3);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(14.5,-3.5,8.3);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(17.6,-3.5,8.3);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(20.7,-3.5,8.3);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(23.5,-3.5,8.3);  
        glScaled(2.5,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // baris 4 sejajar X  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(2.1,-3.5,11.4);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(5.2,-3.5,11.4);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(8.3,-3.5,11.4);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(11.4,-3.5,11.4);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(14.5,-3.5,11.4);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(17.6,-3.5,11.4);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(20.7,-3.5,11.4);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                       
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(23.5,-3.5,11.4);  
        glScaled(2.5,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // baris 5 sejajar X  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(2.1,-3.5,14.5);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(5.2,-3.5,14.5);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(8.3,-3.5,14.5);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(11.4,-3.5,14.5);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(14.5,-3.5,14.5);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(17.6,-3.5,14.5);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(20.7,-3.5,14.5);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(23.5,-3.5,14.5);  
        glScaled(2.5,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // baris 6 sejajar X  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(2.1,-3.5,17.6);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(5.2,-3.5,17.6);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(8.3,-3.5,17.6);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(11.4,-3.5,17.6);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(14.5,-3.5,17.6);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(17.6,-3.5,17.6);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(20.7,-3.5,17.6);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(23.5,-3.5,17.6);  
        glScaled(2.5,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // baris 7 sejajar X  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(2.1,-3.5,20.7);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(5.2,-3.5,20.7);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(8.3,-3.5,20.7);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(11.4,-3.5,20.7);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(14.5,-3.5,20.7);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(17.6,-3.5,20.7);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(20.7,-3.5,20.7);  
        glScaled(3.0,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(23.5,-3.5,20.7);  
        glScaled(2.5,0.6,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // baris 8 sejajar X  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(2.1,-3.5,23.5);  
        glScaled(3.0,0.6,2.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(5.2,-3.5,23.5);  
        glScaled(3.0,0.6,2.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(8.3,-3.5,23.5);  
        glScaled(3.0,0.6,2.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(11.4,-3.5,23.5);  
        glScaled(3.0,0.6,2.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(14.5,-3.5,23.5);  
        glScaled(3.0,0.6,2.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(17.6,-3.5,23.5);  
        glScaled(3.0,0.6,2.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(20.7,-3.5,23.5);  
        glScaled(3.0,0.6,2.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Ubin  =================================================>  
        glTranslated(23.5,-3.5,23.5);  
        glScaled(2.5,0.6,2.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
  
    // Isi Kamar  =======================================================================>  
                                                                                // Lampu  
    glPushMatrix();  // Bola Lampu  ===========================================>  
        glTranslated(13.0,9.0,13.0);  
        glScaled(2.5,0.8,2.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Dudukan Lampu  ========================================>  
        glTranslated(13.0,9.5,13.0);  
        glScaled(2.5,1.0,2.5);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Tirai  
    glPushMatrix();  // Dudukan Besi Kecil Kanan  =============================>  
        glTranslated(0.5,6.8,20.5);  
        glScaled(0.8,0.2,0.2);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Dudukan Besi Kecil Kiri  ==============================>  
        glTranslated(0.5,6.8,22.5);  
        glScaled(0.8,0.2,0.2);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Dudukan Besi Panjang  =================================>  
        glTranslated(0.7,6.8,21.5);  
        glScaled(0.2,0.2,4.0);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tali Pengaturan Tirai  ================================>  
        glTranslated(0.7,4.5,19.6);  
        glScaled(0.06,4.5,0.06);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Gantelan Tali  ========================================>  
        glTranslated(0.7,2.2,19.6);  
        glScaled(0.1,0.4,0.1);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Tirai Besi 1 Dari Kiri  ===============================>  
        glTranslated(0.7,3.0,19.8);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 2 Dari Kiri  ===============================>  
        glTranslated(0.7,3.0,20.1);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 3 Dari Kiri  ===============================>  
        glTranslated(0.7,3.0,20.4);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 4 Dari Kiri  ===============================>  
        glTranslated(0.7,3.0,20.7);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 5 Dari Kiri  ===============================>  
        glTranslated(0.7,3.0,21.0);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 6 Dari Kiri  ===============================>  
        glTranslated(0.7,3.0,21.3);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 7 Dari Kiri  ===============================>  
        glTranslated(0.7,3.0,21.6);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 8 Dari Kiri  ===============================>  
        glTranslated(0.7,3.0,21.9);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 9 Dari Kiri  ===============================>  
        glTranslated(0.7,3.0,22.2);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 10 Dari Kiri  ==============================>  
        glTranslated(0.7,3.0,22.5);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Tirai Besi 11 Dari Kiri  ==============================>  
        glTranslated(0.7,3.0,22.8);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 12 Dari Kiri  ==============================>  
        glTranslated(0.7,3.0,23.1);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tirai Besi 13 Dari Kiri  ==============================>  
        glTranslated(0.7,3.0,23.4);  
        glScaled(0.2,7.5,0.01);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Tempat Tidur  
    glPushMatrix();  // Dudukan Dipan  ========================================>  
        glTranslated(8.30,-3.0,6.0);  
        glScaled(14.5,0.5,9.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Dipan  ================================================>  
        glTranslated(8.25,-2.7,6.0);  
        glScaled(15.5,0.5,10.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Sandaran  =============================================>  
        glTranslated(0.75,-0.6,6.0);  
        glScaled(0.5,3.8,10.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Motif Lingkaran  ======================================>  
        glTranslated(0.7,0.0,6.0);  
        glScaled(0.5,1.2,5.0);  
        glColor3d(1.0,0.6,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Kotak Kanan  ====================================>  
        glTranslated(0.8,-0.6,2.2);  
        glScaled(0.7,3.0,1.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Motif Kotak Kiri  =====================================>  
        glTranslated(0.8,-0.6,9.8);  
        glScaled(0.7,3.0,1.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bantal Merah  =========================================>  
        glTranslated(3.7,-0.8,6.0);  
        glScaled(2.0,0.7,3.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Selimut Putih  ========================================>  
        glTranslated(13.7,-1.0,6.0);  
        glScaled(2.5,0.4,8.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Kasur Merah Baris 1 ===================================>  
        glTranslated(8.25,-1.8,2.0);  
        glScaled(14.5,1.2,1.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kasur Putih Baris 2 ===================================>  
        glTranslated(8.25,-1.8,3.0);  
        glScaled(14.5,1.2,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kasur Merah Baris 3 ===================================>  
        glTranslated(8.25,-1.8,4.0);  
        glScaled(14.5,1.2,1.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kasur Putih Baris 4 ===================================>  
        glTranslated(8.25,-1.8,5.0);  
        glScaled(14.5,1.2,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kasur Merah Baris 5 ===================================>  
        glTranslated(8.25,-1.8,6.0);  
        glScaled(14.5,1.2,1.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kasur Putih Baris 6 ===================================>  
        glTranslated(8.25,-1.8,7.0);  
        glScaled(14.5,1.2,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kasur Merah Baris 7 ===================================>  
        glTranslated(8.25,-1.8,8.0);  
        glScaled(14.5,1.2,1.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kasur Putih Baris 8 ===================================>  
        glTranslated(8.25,-1.8,9.0);  
        glScaled(14.5,1.2,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kasur Merah Baris 9 ===================================>  
        glTranslated(8.25,-1.8,10.0);  
        glScaled(14.5,1.2,1.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Pot Tumbuhan  
    glPushMatrix();  // Kotak Putih Bawah  ====================================>  
        glTranslated(23.5,-2.45,10.0);  
        glScaled(2.0,0.6,2.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Kotak Putih Atas  =====================================>  
        glTranslated(23.5,-1.05,10.0);  
        glScaled(1.5,0.3,1.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Bola Hitam Tengah  ====================================>  
        glTranslated(23.5,-2.05,10.0);  
        glScaled(0.9,1.2,0.9);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,10.0);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,10.0);  
        glRotated(7,10,0,-4);  
        glScaled(0.1,3.0,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,10.0);  
        glRotated(7,10,0,7);  
        glScaled(0.1,2.8,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,10.0);  
        glRotated(-6,10,0,5);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,10.0);  
        glRotated(-6,10,0,-6);  
        glScaled(0.1,2.9,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,10.0);  
        glRotated(12,10,0,-7);  
        glScaled(0.1,3.1,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,10.0);  
        glRotated(12,10,0,8);  
        glScaled(0.1,3.0,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,10.0);  
        glRotated(-14,10,0,-5);  
        glScaled(0.1,2.7,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,10.0);  
        glRotated(-14,10,0,9);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
                                                                                // Lemari  
    glPushMatrix();  // Dudukan Lemari  =======================================>  
        glTranslated(23.5,-3.0,6.0);  
        glScaled(2.0,0.5,10.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Lemari  ===============================================>  
        glTranslated(23.5,2.0,4.5);  
        glScaled(2.6,9.5,7.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu Lemari  =========================================>  
        glTranslated(22.15,2.0,3.3);  
        glScaled(0.2,8.5,3.6);  
        glColor3d(1.0,0.6,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Motif 1 dari bawah  ===================================>  
        glTranslated(22.0,-1.2,3.3);  
        glScaled(0.2,1.0,2.6);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Motif 2 dari bawah  ===================================>  
        glTranslated(22.0,0.8,3.3);  
        glScaled(0.2,1.0,2.6);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Motif 3 dari bawah  ===================================>  
        glTranslated(22.0,2.8,3.3);  
        glScaled(0.2,1.0,2.6);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Motif 1 dari bawah  ===================================>  
        glTranslated(22.0,4.8,3.3);  
        glScaled(0.2,1.0,2.6);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Cermin Lemari  ========================================>  
        glTranslated(22.15,2.0,6.8);  
        glScaled(0.2,8.5,2.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Rak Lemari  ===========================================>  
        glTranslated(23.5,3.7,6.0);  
        glScaled(2.0,0.5,10.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Lampu Meja  
    glPushMatrix();  // Kotak Putih Atas  =====================================>  
        glTranslated(23.5,5.5,10.0);  
        glRotated(-90,1,0,0);  
        glScaled(1.5,1.5,1.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCone(1,1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Bola Hitam Tengah  ====================================>  
        glTranslated(23.5,4.65,10.0);  
        glScaled(0.9,1.2,0.9);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Kotak Putih Atas  =====================================>  
        glTranslated(1.7,0.85,23.5);  
        glRotated(-90,1,0,0);  
        glScaled(1.5,1.5,1.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCone(1,1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Bola Hitam Tengah  ====================================>  
        glTranslated(1.7,0.0,23.5);  
        glScaled(0.9,1.2,0.9);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
                                                                                      
                                                                                // Lampu Dinding  
    glPushMatrix();  // Kerucut Atas (Kanan)  =================================>  
        glTranslated(1.0,5.9,2.0);  
        glRotated(-90,1,0,0);  
        glScaled(1.0,1.0,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCone(1,1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Bola Hitam Tengah (Kanan)  ============================>  
        glTranslated(1.0,5.7,2.0);  
        glScaled(0.4,1.0,0.4);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Kotak Putih Dudukan (Kanan)  ==========================>  
        glTranslated(0.7,5.5,2.0);  
        glScaled(0.8,0.5,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // // Kerucut Atas (Kiri)  ===============================>  
        glTranslated(1.0,5.9,10.15);  
        glRotated(-90,1,0,0);  
        glScaled(1.0,1.0,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCone(1,1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Bola Hitam Tengah (Kiri)  =============================>  
        glTranslated(1.0,5.7,10.15);  
        glScaled(0.4,1.0,0.4);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Kotak Putih Bawah (Kiri)  =============================>  
        glTranslated(0.7,5.5,10.15);  
        glScaled(0.8,0.5,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                //  Lukisan  
    glPushMatrix();  // Frame  ================================================>  
        glTranslated(0.7,5.5,6.1);  
        glScaled(0.15,5.0,5.0);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kanvas  ===============================================>  
        glTranslated(0.7,5.5,6.1);  
        glScaled(0.2,4.0,4.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Merah Baring  ===================================>  
        glTranslated(0.8,6.5,5.5);  
        glScaled(0.2,0.5,2.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
    //  
    glPushMatrix();  // Motif Merah Baring  ===================================>  
        glTranslated(0.8,6.8,7.2);  
        glScaled(0.4,0.5,1.4);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Merah Baring  ===================================>  
        glTranslated(0.8,4.9,7.2);  
        glScaled(0.4,0.5,1.4);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Merah Baring  ===================================>  
        glTranslated(0.8,4.0,7.0);  
        glScaled(0.4,0.5,2.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Merah Baring  ===================================>  
        glTranslated(0.8,4.8,5.3);  
        glScaled(0.4,1.0,2.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Merah Baring  ===================================>  
        glTranslated(0.8,5.8,6.1);  
        glScaled(0.4,0.3,3.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Merah Bardiri  ==================================>  
        glTranslated(0.8,6.0,6.0);  
        glScaled(0.2,1.8,0.7);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Motif Merah Bardiri  ==================================>  
        glTranslated(0.8,5.2,7.25);  
        glScaled(0.2,2.3,0.7);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Merah Bardiri  ==================================>  
        glTranslated(0.8,5.0,5.15);  
        glScaled(0.2,2.4,0.8);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Merah Bardiri  ==================================>  
        glTranslated(0.8,4.3,6.3);  
        glScaled(0.2,1.4,0.4);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Merah Bardiri  ==================================>  
        glTranslated(0.8,6.8,7.6);  
        glScaled(0.2,1.0,0.4);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Motif Merah Bardiri  ==================================>  
        glTranslated(0.8,6.6,4.7);  
        glScaled(0.2,1.3,0.9);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Meja Komputer  
    glPushMatrix();  // Dudukan Meja  =========================================>  
        glTranslated(23.5,-3.0,18.5);  
        glScaled(2.0,0.5,11.0);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Meja Panjang  =========================================>  
        glTranslated(23.5,-2.6,18.5);  
        glScaled(2.8,0.5,12.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Meja Komputer Pas  ====================================>  
        glTranslated(21.8,-2.6,18.5);  
        glScaled(2.0,0.5,7.8);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kaki Meja +Z  =========================================>  
        glTranslated(23.55,-0.2,22.25);  
        glScaled(2.0,4.5,0.2);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Kaki Meja -Z  =========================================>  
        glTranslated(23.55,-0.2,14.75);  
        glScaled(2.0,4.5,0.2);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Dudukan Meja Atas  ====================================>  
        glTranslated(23.55,2.0,18.5);  
        glScaled(2.0,0.3,7.8);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Alas Duduk  
    glPushMatrix();  // Alas Duduk  ===========================================>  
        glTranslated(15.5,-3.0,18.5);  
        glScaled(5.0,0.5,5.0);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
                                                                                // Speaker  
    glPushMatrix();  // Box Hitam -Z  =========================================>  
        glTranslated(23.7,0.4,13.4);  
        glScaled(2.0,5.5,2.0);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Depan Box -Z  =========================================>  
        glTranslated(22.7,0.7,13.4);  
        glScaled(0.3,4.5,1.5);  
        glColor3d(0.2,0.2,0.2);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Box Hitam +Z  =========================================>  
        glTranslated(23.7,0.4,23.6);  
        glScaled(2.0,5.5,2.0);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Depan Box +Z  =========================================>  
        glTranslated(22.7,0.7,23.6);  
        glScaled(0.3,4.5,1.5);  
        glColor3d(0.2,0.2,0.2);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Tombol Tengah  ========================================>  
        glTranslated(22.7,-2.0,23.6);  
        glScaled(0.15,0.15,0.15);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Tombol -Z  ============================================>  
        glTranslated(22.7,-2.0,23.1);  
        glScaled(0.15,0.15,0.15);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Tombol +Z  ============================================>  
        glTranslated(22.7,-2.0,24.1);  
        glScaled(0.15,0.15,0.15);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
                                                                                // CPU  
    glPushMatrix();  // Casing Utama  =========================================>  
        glTranslated(22.9,-0.6,15.7);  
        glScaled(3.8,3.6,1.5);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Belakang  =============================================>  
        glTranslated(24.8,-0.6,15.7);  
        glScaled(0.05,3.0,1.0);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Depan  ================================================>  
        glTranslated(20.95,-0.6,15.7);  
        glScaled(0.05,3.0,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // CD Room  ==============================================>  
        glTranslated(20.9,-0.2,15.5);  
        glScaled(0.05,1.5,0.3);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // CD Room  ==============================================>  
        glTranslated(20.9,-0.2,15.9);  
        glScaled(0.05,1.5,0.3);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Tombol On/Off  ========================================>  
        glTranslated(20.95,-1.5,15.7);  
        glScaled(0.1,0.1,0.1);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
                                                                                // Monitor  
    glPushMatrix();  // Frame Monitor  ========================================>  
        glTranslated(23.5,-0.6,18.5);  
        glRotated(-7,0,0,1);  
        glScaled(0.3,2.6,3.5);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Frame Monitor Blkng  ==================================>  
        glTranslated(23.8,-0.6,18.5);  
        glScaled(0.3,1.5,1.5);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Penyangga  ============================================>  
        glTranslated(24.1,-1.3,18.5);  
        glScaled(0.3,2.0,1.0);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Dudukan Monitor  ======================================>  
        glTranslated(23.6,-2.3,18.5);  
        glScaled(1.5,0.3,1.5);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // LCD  ==================================================>  
        glTranslated(23.3,-0.6,18.5);  
        glRotated(-7,0,0,1);  
        glScaled(0.05,2.0,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Mouse Pad  
    glPushMatrix();  // Mouse Pad  ============================================>  
        glTranslated(21.8,-2.35,21.3);  
        glScaled(1.7,0.05,1.5);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Mouse   
    glPushMatrix();  // Mouse  ================================================>  
        glTranslated(21.8,-2.2,21.3);  
        glScaled(0.5,0.2,0.3);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Klik Kiri  ============================================>  
        glTranslated(22.1,-2.1,21.2);  
        glScaled(0.2,0.1,0.1);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Klik Kanan  ===========================================>  
        glTranslated(22.1,-2.1,21.4);  
        glScaled(0.2,0.1,0.1);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
                                                                                // Keyboard  
    glPushMatrix();  // Kotak Putih  ==========================================>  
        glTranslated(21.8,-2.3,18.5);  
        glRotated(6,0,0,1);  
        glScaled(1.4,0.1,3.7);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Tombol Keyboar Huruf  =================================>  
        glTranslated(21.8,-2.2,18.0);  
        glRotated(6,0,0,1);  
        glScaled(1.0,0.1,2.3);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Tombol Keyboard Angka  ================================>  
        glTranslated(21.8,-2.2,19.8);  
        glRotated(6,0,0,1);  
        glScaled(1.0,0.1,0.8);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // TV Tunner  
    glPushMatrix();  // TV Tunner  ============================================>  
        glTranslated(23.5,-1.9,21.3);  
        glScaled(0.7,1.5,0.25);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Lampu TV Tunner  ======================================>  
        glTranslated(23.2,-1.6,21.3);  
        glScaled(0.2,0.2,0.26);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Printer  
    glPushMatrix();  // Casing Utama  =========================================>  
        glTranslated(23.6,2.6,18.5);  
        glScaled(2.0,0.8,4.5);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Casing Scanner  =======================================>  
        glTranslated(23.4,3.1,18.5);  
        glScaled(1.7,0.2,4.5);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Engsel Scanner -Z  ====================================>  
        glTranslated(24.42,3.1,16.5);  
        glScaled(0.35,0.2,0.5);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Engsel Scanner +Z  ====================================>  
        glTranslated(24.42,3.1,20.5);  
        glScaled(0.35,0.2,0.5);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Sandaran Kertas  ======================================>  
        glTranslated(24.8,3.2,18.5);  
        glRotated(60,0,0,1);  
        glScaled(1.0,0.1,3.5);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Tempat Keluar Kertas  =================================>  
        glTranslated(22.3,2.35,18.5);  
        glRotated(-10,0,0,1);  
        glScaled(1.5,0.1,3.5);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Rak Buku  
    glPushMatrix();  // Papan Belakang Sejajar Sumbu Z  =======================>  
        glTranslated(0.75,-1.8,21.5);  
        glScaled(0.3,1.7,6.0);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Papan Atas Sejajar Sumbu Z  ===========================>  
        glTranslated(1.6,-1.0,21.5);  
        glScaled(2.0,0.3,6.0);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Papan Bawah Sejajar Sumbu Z  ==========================>  
        glTranslated(1.6,-2.8,21.5);  
        glScaled(2.0,0.3,6.0);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Papan Dudukan Sejajar Sumbu Z  ========================>  
        glTranslated(1.6,-3.0,21.5);  
        glScaled(1.6,0.3,5.6);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Papan Belakang Sejajar Sumbu X  =======================>  
        glTranslated(5.6,-1.8,24.35);  
        glScaled(10.0,1.7,0.3);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Papan Atas Sejajar Sumbu X  ===========================>  
        glTranslated(6.6,-1.0,23.5);  
        glScaled(8.0,0.3,2.0);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Papan Bawah Sejajar Sumbu X  ==========================>  
        glTranslated(6.6,-2.8,23.5);  
        glScaled(8.0,0.3,2.0);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Papan Dudukan Sejajar Sumbu X  ========================>          
        glTranslated(6.2,-3.0,23.5);  
        glScaled(8.0,0.3,1.6);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Papan Berdiri Sumbu Z  ================================>  
        glTranslated(1.6,-1.9,18.65);  
        glScaled(2.0,2.0,0.3);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Papan Berdiri Sumbu X  ================================>  
        glTranslated(10.45,-1.9,23.4);  
        glScaled(0.3,2.0,2.0);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Buku  
    glPushMatrix();  // Buku 1 Dari Belakang  =================================>  
        glTranslated(1.6,-2.0,19.0);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 2 Dari Belakang  =================================>  
        glTranslated(1.6,-2.0,19.3);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Buku 3 Dari Belakang  =================================>  
        glTranslated(1.6,-2.0,19.6);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(0.0,0.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 4 Dari Belakang  =================================>  
        glTranslated(1.6,-2.0,19.9);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(1.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 5 Dari Belakang  =================================>  
        glTranslated(1.6,-2.0,20.2);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Buku 6 Dari Belakang  =================================>  
        glTranslated(1.6,-2.0,20.5);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(1.0,0.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 7 Dari Belakang  =================================>  
        glTranslated(1.6,-2.0,20.8);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(1.0,0.0,0.5);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 8 Dari Belakang  =================================>  
        glTranslated(1.6,-2.0,21.1);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(0.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Buku 9 Dari Belakang  =================================>  
        glTranslated(1.6,-2.0,21.4);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(0.0,1.0,0.5);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 10 Dari Belakang  ================================>  
        glTranslated(1.6,-2.0,21.7);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 11 Dari Belakang  ================================>  
        glTranslated(1.6,-2.0,22.0);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 12 Dari Belakang  ================================>  
        glTranslated(1.6,-2.0,22.3);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Buku 13 Dari Belakang  ================================>  
        glTranslated(1.6,-2.0,22.6);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(0.0,0.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 14 Dari Belakang  ================================>  
        glTranslated(1.6,-2.0,22.9);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(1.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 15 Dari Belakang  ================================>  
        glTranslated(1.6,-2.0,23.2);  
        glScaled(1.2,1.3,0.3);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 1 Dari Kiri  =====================================>  
        glTranslated(2.2,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 2 Dari Kiri  =====================================>  
        glTranslated(2.5,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 3 Dari Kiri  =====================================>  
        glTranslated(2.8,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 4 Dari Kiri  =====================================>  
        glTranslated(3.1,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,0.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 5 Dari Kiri  =====================================>  
        glTranslated(3.4,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 6 Dari Kiri  =====================================>  
        glTranslated(3.7,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 7 Dari Kiri  =====================================>  
        glTranslated(4.0,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 8 Dari Kiri  =====================================>  
        glTranslated(4.3,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,0.5);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 9 Dari Kiri  =====================================>  
        glTranslated(4.6,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 10 Dari Kiri  ====================================>  
        glTranslated(4.9,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 11 Dari Kiri  ====================================>  
        glTranslated(5.2,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,0.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 12 Dari Kiri  ====================================>  
        glTranslated(5.5,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 13 Dari Kiri  ====================================>  
        glTranslated(5.8,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 14 Dari Kiri  ====================================>  
        glTranslated(6.1,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 15 Dari Kiri  ====================================>  
        glTranslated(6.4,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,0.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 16 Dari Kiri  ====================================>  
        glTranslated(6.7,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 17 Dari Kiri  ====================================>  
        glTranslated(7.0,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 18 Dari Kiri  ====================================>  
        glTranslated(7.3,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 19 Dari Kiri  ====================================>  
        glTranslated(7.6,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,0.5);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 20 Dari Kiri  ====================================>  
        glTranslated(7.9,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 21 Dari Kiri  ====================================>  
        glTranslated(8.2,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 22 Dari Kiri  ====================================>  
        glTranslated(8.5,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,0.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 23 Dari Kiri  ====================================>  
        glTranslated(8.8,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 24 Dari Kiri  ====================================>  
        glTranslated(9.1,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 25 Dari Kiri  ====================================>  
        glTranslated(9.4,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,0.5);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 26 Dari Kiri  ====================================>  
        glTranslated(9.7,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 27 Dari Kiri  ====================================>  
        glTranslated(10.0,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Buku 28 Dari Kiri  ====================================>  
        glTranslated(10.3,-2.0,23.5);  
        glScaled(0.3,1.3,1.2);  
        glColor3d(0.0,0.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
                                                                                // Kipas Angin  
    glPushMatrix();  // Dudukan Kipas  ========================================>  
        glTranslated(9.3,-0.8,23.65);  
        glScaled(0.85,0.2,0.85);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Tombol Kipas Tengah  ==================================>  
        glTranslated(9.3,-0.7,23.4);  
        glScaled(0.1,0.2,0.2);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Tombol Kipas  =========================================>  
        glTranslated(9.5,-0.7,23.4);  
        glScaled(0.1,0.2,0.2);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Tombol Kipas Merah  ===================================>  
        glTranslated(9.1,-0.7,23.4);  
        glScaled(0.1,0.2,0.2);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Tiang Kipas  ==========================================>  
        glTranslated(9.3,0.0,23.95);  
        glScaled(0.4,2.0,0.4);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Mesin Kipas  ==========================================>  
        glTranslated(9.3,1.2,24.1);  
        glScaled(0.55,0.55,0.7);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Panel  ================================================>  
        glTranslated(9.1,1.4,24.6);  
        glScaled(0.07,0.4,0.07);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // As Kipas  =============================================>  
        glTranslated(9.3,1.2,23.75);  
        glScaled(0.2,0.2,0.8);  
        glColor3d(.5,0.5,0.5);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Jaring Kipas  =========================================>  
        glTranslated(9.3,1.2,23.2);  
        glScaled(1.45,1.45,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutWireSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Baling Baling Kipas  ==================================>  
        glTranslated(9.3,1.2,23.2);  
        glRotated(RotasiKipas,0,0,1);  
        glScaled(1.3,0.3,0.08);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Baling Baling Kipas  ==================================>  
        glTranslated(9.3,1.2,23.2);  
        glRotated(RotasiKipas,0,0,1);  
        glScaled(0.3,1.3,0.08);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  
  
    glutSwapBuffers();  
    glutPostRedisplay();                                    // Redisplay Screen  
}  
  
  
void keyboard( unsigned char key, int x, int y ) {          // Pada Keyboard  
    switch ( key ) {                                        // Inisialisasi Keyboard  
        case 27:                                            // Jika ESC D tekan  
            exit( 0 );                                      // Tutup Program  
        break;                                                  }  
glutPostRedisplay();                                        // Redisplay screen  
}  
  
  
/* Prosedur spesial key OpenGL */  
void specialkeys (int key, int x, int y){  
    switch (key) {  
        case GLUT_KEY_LEFT:  
            RotationSpeedX -= 0.1;  
            if ( RotationSpeedX <= -2.0 )  
                RotationSpeedX = -2.0;  
        break;  
        case GLUT_KEY_RIGHT:  
            RotationSpeedX += 0.1;  
            if ( RotationSpeedX >= 1.5 )  
                RotationSpeedX = 1.5;  
        break;  
        case GLUT_KEY_UP:  
            zCord += 0.2;  
            if ( zCord >= -10.0 )  
                zCord = -10.0;  
        break;  
        case GLUT_KEY_DOWN:  
            zCord -= 0.1;  
            if ( zCord <= -60.0 )  
                zCord = -60.0;  
        break;  
        case GLUT_KEY_PAGE_UP:  
            yCord += 0.1f;  
            if ( yCord >= 15.0 )  
                yCord = 15.0;  
        break;  
        case GLUT_KEY_PAGE_DOWN:  
            yCord -= 0.1;  
            if ( yCord <= -15.0 )  
                yCord = -15.0;  
        break;  
        case GLUT_KEY_F1:  
            KecRot += 0.3;  
            if ( KecRot >= 0.0 )  
                KecRot = 0.0;  
        break;  
        case GLUT_KEY_F2:  
            KecRot -= 0.2;  
            if ( KecRot <= -50.0 )  
                KecRot = -50.0;  
        break;  
        case GLUT_KEY_F3:  
            KecRot2 += 0.3;  
            if ( KecRot2 >= 0.0 )  
                KecRot2 = 0.0;  
        break;  
        case GLUT_KEY_F4:  
            KecRot2 -= 0.2;  
            if ( KecRot2 <= -50.0 )  
                KecRot2 = -50.0;  
        break;  
    default:  
        break;  
    }  
    glutPostRedisplay();  
}  
  
  
  
/* ProgramUtama */  
  
int main(int argc, char *argv[])  
{  
    glutInit(&argc, argv);  
    glutInitWindowSize(800,600);  
    glutInitWindowPosition(200,100);  
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  
  
    glutCreateWindow ("Kelompok xxx");  
  
    glutReshapeFunc(resize);  
    glutDisplayFunc(display);  
    glutKeyboardFunc(keyboard);  
    glutSpecialFunc(specialkeys);   
  
    glClearColor(1,1,1,1);   
    glEnable(GL_CULL_FACE);  
    glCullFace(GL_BACK);  
  
    glEnable(GL_DEPTH_TEST);  
    glDepthFunc(GL_LESS);  
  
    glEnable(GL_LIGHT0);  
    glEnable(GL_NORMALIZE);  
    glEnable(GL_COLOR_MATERIAL);  
    glEnable(GL_LIGHTING);  
  
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);  
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);  
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);  
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);  
  
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);  
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);  
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);  
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);  
  
    glutMainLoop();  
  
    return EXIT_SUCCESS;  
}  


