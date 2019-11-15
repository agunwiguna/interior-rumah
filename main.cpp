#include <windows.h>
#include <GL/gl.h>
#include <GL/glaux.h>
#include <GL/glu.h>
//#include <GL/glui.h>
#include <GL/glut.h>
#include <stdlib.h>

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

	// Tembok Kanan ===========================================================================>

	glPushMatrix();  // Tembok Hitam Sumbu X Kiri  ============================>
	glTranslated(8.0,-1.0,-2.2);
	glScaled(16.0,5.0,0.5);
	glColor3d(0.0,0.0,0.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Putih Sumbu X Kiri  ============================>
	glTranslated(8.0,2.0,-2.2);
	glScaled(16.0,1.0,0.5);
	glColor3d(1.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Biru Sumbu X Kiri  ============================>
	glTranslated(8.0,6.0,-2.2);
	glScaled(16.0,7.0,0.5);
	glColor3d(0.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Hitam Sumbu X Kanan  ===========================>
	glTranslated(23.5,-1.0,-2.2);
	glScaled(2.9,5.0,0.5);
	glColor3d(0.0,0.0,0.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Putih Sumbu X Kanan  ===========================>
	glTranslated(23.5,2.0,-2.2);
	glScaled(2.9,1.0,0.5);
	glColor3d(1.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Biru Sumbu X Kanan  ===========================>
	glTranslated(23.5,6.0,-2.2);
	glScaled(2.9,7.0,0.5);
	glColor3d(0.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Biru Sumbu X Atas  ============================>
	glTranslated(19,9.0,-2.2);
	glScaled(6.1,1.0,0.5);
	glColor3d(0.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

// Tembok Kiri ===========================================================================>

	glPushMatrix();  // Tembok Hitam Sumbu Z Kanan  ===========================>
	glTranslated(0.2,-1.0,0.5);
	glScaled(0.5,5.0,1.0);
	glColor3d(0.0,0.0,0.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Putih Sumbu Z Kanan  ===========================>
	glTranslated(0.2,2.0,0.5);
	glScaled(0.5,1.0,1.0);
	glColor3d(1.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Biru Sumbu Z Kanan  ===========================>
	glTranslated(0.2,6.0,0.5);
	glScaled(0.5,7.0,1.0);
	glColor3d(0.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Biru Sumbu Z Atas  ============================>
	glTranslated(0.2,9.0,4.0);
	glScaled(0.5,1.0,6.1);
	glColor3d(0.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Hitam Sumbu Z Kiri  ============================>
	glTranslated(0.2,-1.0,16.0);
	glScaled(0.5,5.0,18.0);
	glColor3d(0.0,0.0,0.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Putih Sumbu Z Kiri  ============================>
	glTranslated(0.2,2.0,16.0);
	glScaled(0.5,1.0,18.0);
	glColor3d(1.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Biru Sumbu Z Kiri  ============================>
	glTranslated(0.2,6.0,16.0);
	glScaled(0.5,7.0,18.0);
	glColor3d(0.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

// Lantai Ruang Keluarga  ==========================================================================>

	glPushMatrix();  
	glTranslated(12.5,-3.5,11.3);
	glScaled(25.0,0.5,27.5);
	glColor3d(0.0,.0,0.0);
	glutSolidCube(1);
	glPopMatrix();


// Tembok ===========================================================================>

	glPushMatrix();  // Tembok Hitam Sumbu X  ===========================>
	glTranslated(-12.0,-1.0,0.2);
	glScaled(24.0,5.0,0.5);
	glColor3d(0.0,0.0,0.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Putih Sumbu X  ===========================>
	glTranslated(-12.0,2.0,0.2);
	glScaled(24.0,1.0,0.5);
	glColor3d(1.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Biru Sumbu X  ===========================>
	glTranslated(-12.0,6.0,0.2);
	glScaled(24.0,7.0,0.5);
	glColor3d(0.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

// Lantai Ruang Tamu  ==========================================================================>


	//=================================================================================================================================================
// RUANG TAMU
//=================================================================================================================================================

// LANTAI
glPushMatrix(); 
glTranslated(-12.0,-3.5,12.5);
glScaled(24.0,0.5,25.0);
glColor3ub(255, 255, 255);
glutSolidCube(1);
glPopMatrix();

//AC
	glPushMatrix();
		glTranslated(-12,6.5,1);
		glScaled(4.0, 1.5, 0.5);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-12,6.0,1.18);
		glScaled(3.9, 0.13, 0.2);
	    glColor3d(0.0, 0.0, 0.0);
	    glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(-12,6.3,1.18);
		glScaled(3.9, 0.14, 0.2);
	    glColor3d(0.0, 0.0, 0.0);
	    glutSolidCube(1);
	glPopMatrix();
	
// LAMPU DINDING
	// lampu kanan
	glPushMatrix();  // // Kerucut Atas (Kiri)  ===============================>  
        glTranslated(-17,6.5,1.2);  
        glRotated(-90,1,0,0);  
        glScaled(1.0,1.0,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCone(1,1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Bola Hitam Tengah (Kiri)  =============================>  
        glTranslated(-17,5.75,1.2);  
        glScaled(0.4,1.0,0.4);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Kotak Putih Bawah (Kiri)  =============================>  
        glTranslated(-17,5.75,0.4);  
        glScaled(0.5,0.5,0.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
    
    //lampu kiri
    glPushMatrix();  // // Kerucut Atas (Kiri)  ===============================>  
        glTranslated(-7,6.5,1.2);  
        glRotated(-90,1,0,0);  
        glScaled(1.0,1.0,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCone(1,1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Bola Hitam Tengah (Kiri)  =============================>  
        glTranslated(-7,5.75,1.2);  
        glScaled(0.4,1.0,0.4);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Kotak Putih Bawah (Kiri)  =============================>  
        glTranslated(-7,5.75,0.4);  
        glScaled(0.5,0.5,0.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();

// STOP KONTAK
	glPushMatrix();
		glTranslated(-0.125, 5.5, 10);
		glScaled(0.25, 1, 1.5);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(1);
	glPopMatrix();
	
	// stop kontak 1
	glPushMatrix();
		glTranslated(-0.375, 5.5, 9.7);
		glScaled(0.25, 0.6, 0.3);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
	
	// stop kontak 2
	glPushMatrix();
		glTranslated(-0.375, 5.5, 10.3);
		glScaled(0.25, 0.6, 0.3);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();

// FRAME GAMBAR
	glPushMatrix();
		glTranslated(-0.125, 6, 17);
		glScaled(0.25, 5, 8);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(-0.125, 5, 17);
		glScaled(0.30, 0.5, 2);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(-0.125, 6, 17);
		glScaled(0.30, 0.5, 6);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(-0.125, 7, 17);
		glScaled(0.30, 0.5, 2);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(-0.125, 6, 19);
		glScaled(0.30, 3, 0.5);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(-0.125, 6, 17);
		glScaled(0.30, 2, 0.5);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(-0.125, 6, 15);
		glScaled(0.30, 3, 0.5);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
	
	// batas atas
	glPushMatrix();
		glTranslated(-0.375, 8.25, 17);
		glScaled(0.25, 0.5, 8);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
	
	//batas bawah
	glPushMatrix();
		glTranslated(-0.375, 3.75, 17);
		glScaled(0.25, 0.5, 8);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
	
	//batas kiri
	glPushMatrix();
		glTranslated(-0.375, 6, 13.25);
		glScaled(0.25, 4, 0.5);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
	
	//batas kanan
	glPushMatrix();
		glTranslated(-0.375, 6, 20.75);
		glScaled(0.25, 4, 0.5);
	    glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
	glPopMatrix();
    
//SOFA
	// bawah sofa
	glPushMatrix();
		glTranslated(-20.75, -2.75, 14.5);
		glScaled(4.5, 1.0, 10);
		glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
    glPopMatrix();
    
    // belakang sofa
	glPushMatrix();
		glTranslated(-22.75, -0.5, 14.5);
		glScaled(0.5, 3.5, 9);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(1);
    glPopMatrix();
    
    // bantal sofa
	glPushMatrix();
		glTranslated(-20.25, -2.0, 14.5);
		glScaled(3.5, 0.5, 8);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(1);
    glPopMatrix();
    
    // senderan sofa
	glPushMatrix();
		glTranslated(-22.25, -0.5, 14.5);
		glScaled(0.5, 3.5, 9);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(1);
    glPopMatrix();
    
    //sisi kiri sofa
    glPushMatrix();
		glTranslated(-20.75, -1.25, 10.0);
		glScaled(4.5, 2, 1);
		glColor3ub(255, 250, 250);
	    glutSolidCube(1);
    glPopMatrix();
    
    // sisi kanan sofa
	glPushMatrix();
		glTranslated(-20.75, -1.25, 19.0);
		glScaled(4.5, 2, 1);
		glColor3ub(255, 250, 250);
	    glutSolidCube(1);
    glPopMatrix();

//KURSI KECIL 1
	// bawah kursi kecil 1
	glPushMatrix();
		glTranslated(-12, -2.75, 3.75);
		glScaled(7, 1.0, 4.5);
		glColor3d(0.0980, 0.0608, 0.0077);
	    glutSolidCube(1);
    glPopMatrix();
    
    // belakang sofa
	glPushMatrix();
		glTranslated(-12, -0.5, 1.75);
		glScaled(6, 3.5, 0.5);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(1);
    glPopMatrix();
    
    // bantal kursi kecil 1
	glPushMatrix();
		glTranslated(-12, -2.0, 4.25);
		glScaled(5, 0.5, 3.5);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(1);
    glPopMatrix();
    
    // senderan kursi kecil 1
	glPushMatrix();
		glTranslated(-12,-0.5, 2.25);
		glScaled(6, 3.5, 0.5);
	    glColor3ub(255, 250, 250);
	    glutSolidCube(1);
    glPopMatrix();
    
    // sisi kiri kursi kecil 1
    glPushMatrix();
		glTranslated(-15.0, -1.25, 3.75);
		glScaled(1, 2, 4.5);
		glColor3ub(255, 250, 250);
	    glutSolidCube(1);
    glPopMatrix();
    
    // sisi kanan kursi kecil 1
	glPushMatrix();
		glTranslated(-9.0, -1.25, 3.75);
		glScaled(1, 2, 4.5);
		glColor3ub(255, 250, 250);
	    glutSolidCube(1);
    glPopMatrix();

//KARPET
	// dasar karpet
	glPushMatrix();
       glTranslated(-12.0,-3.125,14.5);
       glScalef(10.5,0.25,12.5);
       glColor3ub(196, 186, 174);    
       glutSolidCube(1);
    glPopMatrix();
    
    // motif sumbu x
    glPushMatrix();
       glTranslated(-12.0,-3.125,8.5);
       glScalef(10.6,0.30,0.15);
       glColor3d(0.0980, 0.0608, 0.0077);   
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-12.0,-3.125,10.5);
       glScalef(10.6,0.30,0.15);
       glColor3d(0.0980, 0.0608, 0.0077);   
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-12.0,-3.125,12.5);
       glScalef(10.6,0.30,0.15);
       glColor3d(0.0980, 0.0608, 0.0077);   
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-12.0,-3.125,14.5);
       glScalef(10.6,0.30,0.15);
       glColor3d(0.0980, 0.0608, 0.0077);   
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-12.0,-3.125,16.5);
       glScalef(10.6,0.30,0.15);
       glColor3d(0.0980, 0.0608, 0.0077);   
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-12.0,-3.125,18.5);
       glScalef(10.6,0.30,0.15);
       glColor3d(0.0980, 0.0608, 0.0077);   
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-12.0,-3.125,20.5);
       glScalef(10.6,0.30,0.15);
       glColor3d(0.0980, 0.0608, 0.0077);   
       glutSolidCube(1);
    glPopMatrix();
    
    // motif sumbu z
    glPushMatrix();
       glTranslated(-17.0,-3.125,14.5);
       glScalef(0.15,0.30,12.6);
       glColor3d(0.0980, 0.0608, 0.0077); 
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-15.0,-3.125,14.5);
       glScalef(0.15,0.30,12.6);
       glColor3d(0.0980, 0.0608, 0.0077); 
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-13.0,-3.125,14.5);
       glScalef(0.15,0.30,12.6);
       glColor3d(0.0980, 0.0608, 0.0077); 
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-11.0,-3.125,14.5);
       glScalef(0.15,0.30,12.6);
       glColor3d(0.0980, 0.0608, 0.0077); 
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-9.0,-3.125,14.5);
       glScalef(0.15,0.30,12.6);
       glColor3d(0.0980, 0.0608, 0.0077); 
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-7.0,-3.125,14.5);
       glScalef(0.15,0.30,12.6);
       glColor3d(0.0980, 0.0608, 0.0077); 
       glutSolidCube(1);
    glPopMatrix();

//MEJA
	glPushMatrix();
       glTranslated(-12.0,-0.0,14.5);
       glScalef(6.0,0.5,8.0);
       glColor3ub(255, 250, 250);    
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glTranslated(-12.0,0.25,14.5);
       glScalef(4,0.25,6);
       glColor3f(0.0980, 0.0608, 0.0077);  
       glutSolidCube(1);
    glPopMatrix();
	
	// kaki kiri depan
    glPushMatrix();
       glTranslatef(-14.75,-1.75,18.25);
       glScalef(0.5,3.0,0.5);
       glColor3ub(255, 250, 250);
       glutSolidCube(1);
    glPopMatrix();
	
	// kaki kanan depan
    glPushMatrix();
       glTranslatef(-9.25,-1.75,18.25);
       glScalef(0.5,3.0,0.5);
       glColor3ub(255, 250, 250);
       glutSolidCube(1.0);
    glPopMatrix();
	
	// kaki kiri belakang
    glPushMatrix();
       glTranslatef(-14.75,-1.75,10.75);
       glScalef(0.5,3.0,0.5);
       glColor3ub(255, 250, 250);
       glutSolidCube(1);
    glPopMatrix();
	
	// kaki kanan belakang
    glPushMatrix();
       glTranslatef(-9.25,-1.75,10.75);
       glScalef(0.5,3.0,0.5);
       glColor3ub(255, 250, 250);
       glutSolidCube(1.0);
    glPopMatrix();
	
// LAMPU
	// tiang lampu
	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		glTranslatef(-20.0, 4.5, -1);
		glScaled(0.25, 0.25, 10);
		glColor3ub(255, 250, 250);
		glutSolidTorus(0.4, 0.4, 60, 80);
    glPopMatrix();
    
    // tatakan bawah lampu
    glPushMatrix();
		glColor3ub(46, 79, 219);
		glTranslatef(-20, -3.0, 4.5);
		glScaled(1, 0.1, 1);
		glColor3ub(255, 250, 250);
		glutSolidSphere(2, 5, 5);
	glPopMatrix();
	
	// Head Lampu
	glPushMatrix();
		glTranslatef(-20, 3.5, 4.5);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glColor3d(0.0, 1.0, 0.0);
		glRotated(-90.0, 1.0, 0.0, 0.0);
		glColor3ub(255, 250, 250);
		glutSolidCone(2.0, 2.5, 50, 25);
	glPopMatrix();

// BUNGA
	glPushMatrix();  // Kotak Putih Bawah  ====================================>  
        glTranslated(-20,-3.0,22.5);  
        glScaled(2.0,0.6,2.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Kotak Putih Atas  =====================================>  
        glTranslated(-20.0,-1.05,22.5);  
        glScaled(1.5,0.3,1.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  

    glPushMatrix();  // Bola Hitam Tengah  ====================================>  
        glTranslated(-20.0,-2.05,22.5);  
        glScaled(0.9,1.2,0.9);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-20.0,-0.3,22.5);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-20.0,-0.3,22.5);  
        glRotated(7,10,0,-4);  
        glScaled(0.1,3.0,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-20.0,-0.3,22.5);  
        glRotated(7,10,0,7);  
        glScaled(0.1,2.8,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-20.0,-0.3,22.5);  
        glRotated(-6,10,0,5);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-20.0,-0.3,22.5);  
        glRotated(-6,10,0,-6);  
        glScaled(0.1,2.9,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-20.0,-0.3,22.5);  
        glRotated(12,10,0,-7);  
        glScaled(0.1,3.1,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-20.0,-0.3,22.5);  
        glRotated(12,10,0,8);  
        glScaled(0.1,3.0,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-20.0,-0.3,22.5);  
        glRotated(-14,10,0,-5);  
        glScaled(0.1,2.7,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-20.0,-0.3,22.5);  
        glRotated(-14,10,0,9);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  

	// Tembok ===========================================================================>

	glPushMatrix();  // Tembok Hitam Sumbu Z  ===========================>
	glTranslated(0.2,-1.0,-9.2);
	glScaled(0.5,5.0,18.5);
	glColor3d(0.0,0.0,0.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Putih Sumbu Z  ===========================>
	glTranslated(0.2,2.0,-9.2);
	glScaled(0.5,1.0,18.5);
	glColor3d(1.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Biru Sumbu Z  ===========================>
	glTranslated(0.2,6.0,-9.2);
	glScaled(0.5,7.0,18.5);
	glColor3d(0.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Biru Sumbu Z Atas  ============================>
	glTranslated(0.2,9.0,-21.5);
	glScaled(0.5,1.0,6.1);
	glColor3d(0.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Hitam Sumbu Z  ===========================>
	glTranslated(0.2,-1.0,-26.0);
	glScaled(0.5,5.0,4.0);
	glColor3d(0.0,0.0,0.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Putih Sumbu Z  ===========================>
	glTranslated(0.2,2.0,-26.0);
	glScaled(0.5,1.0,4.0);
	glColor3d(1.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();  // Tembok Biru Sumbu Z  ===========================>
	glTranslated(0.2,6.0,-26.0);
	glScaled(0.5,7.0,4.0);
	glColor3d(0.0,1.0,1.0);
	glutSolidCube(1);
	glPopMatrix();
	
	//ISI RUANG KELUARGA (Harry)
glPushMatrix();  // TV ===========================================>
glTranslated(1.0,5.0,15.7);
glScaled(0.5,5.0,7.0);
glColor3d(0.1,0.1,0.1);  
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // TV layar===========================================>
glTranslated(1.22,5.0,15.7);
glScaled(0.1,4.5,6.5);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Meja di bawah tv bag atas===========================================>
glTranslated(2.6,0.6,15.3);
glScaled(4.0,0.5,16.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Meja di bawah tv bag bwh ===========================================>
glTranslated(2.6,-3.0,15.3);
glScaled(4.0,0.5,16.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Meja di bawah tv bag bwh ===========================================>
glTranslated(2.6,-1.5,13.3);
glScaled(4.0,0.5,4.5);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Meja di bawah tv samping ===========================================>
glTranslated(2.6,-1.2,11.0);
glScaled(4.0,3.5,0.5);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Meja di bawah tv samping ===========================================>
glTranslated(2.6,-1.2,20.0);
glScaled(4.0,3.5,0.5);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Meja di bawah tv tengah ===========================================>
glTranslated(2.6,-1.2,15.5);
glScaled(4.0,3.5,0.5);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Laci meja ===========================================>
glTranslated(4.7,-2.0,13.2);
glScaled(0.2,1.5,4.3);
glColor3d(0.1,0.1,0.1);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // pengangan laci meja ===========================================>
glTranslated(4.8,-2.0,13.2);
glScaled(0.2,0.3,0.9);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

//Karpet
glPushMatrix();  // Karpet ===========================================>
glTranslated(15.0,-3.2,14.3);
glScaled(18.20,0.1,18.20);
glColor3d(1.0,1.0,1.);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Karpet ===========================================>
glTranslated(15.0,-3.19,14.3);
glScaled(16.20,0.1,16.20);
glColor3d(0.1,0.1,0.1);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Karpet ===========================================>
glTranslated(15.0,-3.18,14.3);
glScaled(14.20,0.1,14.20);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Karpet ===========================================>
glTranslated(15.0,-3.17,14.3);
glScaled(12.20,0.1,12.20);
glColor3d(0.1,0.1,0.1);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Karpet ===========================================>
glTranslated(15.0,-3.16,14.3);
glScaled(10.20,0.1,10.20);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Karpet ===========================================>
glTranslated(15.0,-3.11,14.3);
glScaled(8.20,0.1,8.20);
glColor3d(0.1,0.1,0.1);
glutSolidCube(1);
glPopMatrix();

//batas Karpet

//Sofa
glPushMatrix();  // Sofa ===========================================>
glTranslated(20.2,-1.1,14.4);
glScaled(2.9,1.8,9.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Sofa ===========================================>
glTranslated(20.2,-2.5,14.4);
glScaled(2.9,1.0,9.0);
glColor3d(0.1,0.1,0.1);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Sofa kanan ===========================================>
glTranslated(20.0,-1.1,9.8);
glScaled(3.0,4.0,1.3);
glColor3d(0.5,0,0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Sofa kiri===========================================>
glTranslated(20.0,-1.1,18.8);
glScaled(3.0,4.0,1.3);
glColor3d(0.5,0,0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Sofa blakang ===========================================>
glTranslated(22.0,-0.6,14.3);
glScaled(1.0,5.0,10.3);   
glColor3d(0.5,0,0);
glutSolidCube(1);
glPopMatrix();

//batas Sofa
//Meja di sebeliah sofa
glPushMatrix();  // Meja Sofa atas ===========================================>
glTranslated(20.5,-0.2,21.8);
glScaled(3.3,0.3,3.3);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Meja Sofa bawah ===========================================>
glTranslated(20.5,-1.7,21.8);
glScaled(3.3,0.3,3.3);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Meja Sofa kanan ===========================================>
glTranslated(20.5,-1.7,20.3);
glScaled(3.3,2.7,0.3);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Meja Sofa kiri ===========================================>
glTranslated(20.5,-1.7,23.3);
glScaled(3.3,2.7,0.3);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();
//batas meja sofa
//Lampu
glPushMatrix();  // Lampu tiang===========================================>
glTranslated(21.3,1.3,22.2);
glScaled(0.2,2.4,0.2);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Lampu tiang papan ===========================================>
glTranslated(21.3,0.0,22.2);
glScaled(1.1,0.3,1.1);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Lampu tiang papan ===========================================>
glTranslated(21.3,1.4,21.6);
glScaled(0.05,1.1,0.05);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();



 glPushMatrix();  // Bola Hitam Tengah (Kiri)  =============================>  
        glTranslated(21.3,2.0,22.2);  
        glScaled(0.3,0.6,0.3);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();
	
	glPushMatrix();  // // Kerucut Atas (Kiri)  ===============================>  
        glTranslated(21.3,1.7,22.2);  
        glRotated(-90,1,0,0);  
        glScaled(1.0,1.0,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCone(1,1,slices,stacks);  
    glPopMatrix();  
//batas lampu
//Speaker
 glPushMatrix();  // Box Speaker kanan =========================================>  
        glTranslated(2.6,3.6,8.4);  
        glScaled(2.0,5.5,2.0);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Box Speaker Depan  =========================================>  
        glTranslated(3.6,3.9,8.4);  
        glScaled(0.3,4.5,1.5);  
        glColor3d(0.2,0.2,0.2);  
        glutSolidCube(1);  
    glPopMatrix();
	
	 glPushMatrix();  // Box Speaker tombol Depan  =========================================>  
        glTranslated(3.6,1.2,7.8);  
        glScaled(0.2,0.2,0.2);  
        glColor3d(0.2,0.2,0.2);  
        glutSolidSphere(1,slices,stacks); 
    glPopMatrix();
	
	glPushMatrix();  // Box Speaker tombol Depan  =========================================>  
        glTranslated(3.6,1.2,8.4);  
        glScaled(0.2,0.2,0.2);  
        glColor3d(1.0,1.0,1.0);   
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();
	
	glPushMatrix();  // Box Speaker tombol Depan  =========================================>  
        glTranslated(3.6,1.2,9.0);  
        glScaled(0.2,0.2,0.2);  
        glColor3d(0.2,0.2,0.2);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();   
	
 glPushMatrix();  // Box Speaker Kiri =========================================>  
        glTranslated(2.6,3.6,22.2);  
        glScaled(2.0,5.5,2.0);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Box Speaker Depan  =========================================>  
        glTranslated(3.6,3.9,22.2);  
        glScaled(0.3,4.5,1.5);  
        glColor3d(0.2,0.2,0.2);  
        glutSolidCube(1);  
    glPopMatrix(); 
    
    	 glPushMatrix();  // Box Speaker tombol Depan  =========================================>  
        glTranslated(3.6,1.2,21.6);  
        glScaled(0.2,0.2,0.2);  
        glColor3d(0.2,0.2,0.2);  
        glutSolidSphere(1,slices,stacks); 
    glPopMatrix();
	
	glPushMatrix();  // Box Speaker tombol Depan  =========================================>  
        glTranslated(3.6,1.2,22.2);  
        glScaled(0.2,0.2,0.2);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);   
    glPopMatrix();
	
	glPushMatrix();  // Box Speaker tombol Depan  =========================================>  
        glTranslated(3.6,1.2,22.8);  
        glScaled(0.2,0.2,0.2);  
        glColor3d(0.2,0.2,0.2);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
	 
 //batas speaker   
 
 //DVD
    glPushMatrix();  // CD player =========================================>  
        glTranslated(2.6,1.0,15.4);  
        glScaled(2.0,0.5,2.0);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // CD player depan  =========================================>  
        glTranslated(3.2,1.1,15.2);  
        glScaled(0.9,0.2,1.5);  
        glColor3d(0.2,0.2,0.2);  
        glutSolidCube(1);  
    glPopMatrix(); 
    
    glPushMatrix();  // CD player remote =========================================>  
        glTranslated(2.6,1.0,18.4);  
        glScaled(2.0,0.3,0.5);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // CD player remote tombol =========================================>  
        glTranslated(2.9,1.15,18.3);  
        glScaled(0.2,0.1,0.3);  
		glColor3d(0.2,0.2,0.2);   
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // CD player remote tombol =========================================>  
        glTranslated(2.6,1.15,18.3);  
        glScaled(0.2,0.1,0.3);   
		glColor3d(0.2,0.2,0.2);  
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // CD player remote tombol =========================================>  
        glTranslated(2.3,1.15,18.3);  
        glScaled(0.2,0.1,0.3);  
		glColor3d(0.2,0.2,0.2);  
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // CD player remote tombol =========================================>  
        glTranslated(3.5,1.15,18.3);  
        glScaled(0.1,0.1,0.1);  
        glColor3d(1.0,0.0,0.0); ;  
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
//Batas DVD

//Buat hidupin Speaker
glPushMatrix();  // Alat ===========================================>
glTranslated(3.4,-2.0,17.8);
glScaled(2.2,1.3,3.3);
glColor3d(0.1,0.1,0.1);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Alat ===========================================>
glTranslated(4.4,-2.0,17.8);
glScaled(0.25,1.28,1.3);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Alat tombol ===========================================>
glTranslated(4.4,-2.0,16.6);
glScaled(0.27,0.28,0.5);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Alat  tombol ===========================================>
glTranslated(4.4,-1.5,16.6);
glScaled(0.27,0.28,0.5);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Alat ===========================================>
glTranslated(4.4,-2.5,16.6);
glScaled(0.27,0.28,0.5);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Alat ===========================================>
glTranslated(4.4,-1.64,19.2);
glScaled(0.27,0.28,0.2);
glColor3d(1.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();
//batas alat

//Buku di meja
    glPushMatrix();  // Buku =========================================>  
        glTranslated(2.6,1.0,12.4);  
        glScaled(1.5,0.1,2.0); 
        glColor3d(0.1,0.1,0.6);  
        glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();  // Buku =========================================>  
        glTranslated(2.6,1.1,11.8);  
        glScaled(1.5,0.1,2.0); 
        glColor3d(0.1,0.2,0.6);  
        glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();  // Buku =========================================>  
        glTranslated(2.6,-1.2,12.4);  
        glScaled(2.0,0.1,1.5); 
        glColor3d(0.5,0.2,0.7);  
        glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();  // Buku =========================================>  
        glTranslated(2.6,-1.1,11.8);  
        glScaled(2.0,0.1,1.5); 
        glColor3d(0.5,0.3,0.1);  
        glutSolidCube(1);
	glPopMatrix();
	   
//Batas buku meja
//AKHIR MEJA TV

//POT TANAMAN
    glPushMatrix();  // Pot  ====================================>  
        glTranslated(23.5,-1.7,0.0);  
        glScaled(2.0,2.7,2.0);  
        glColor3d(0.5,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // Pot  ====================================>  
        glTranslated(23.5,-1.7,-1.1);  
        glScaled(2.3,3.0,0.3);  
        glColor3d(0.1,0.1,0.1); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // Pot  ====================================>  
        glTranslated(23.5,-1.7,1.1);  
        glScaled(2.3,3.0,0.3);  
        glColor3d(0.1,0.1,0.1); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // Pot  ====================================>  
        glTranslated(24.5,-1.7,0.0);  
        glScaled(0.3,3.0,2.3);  
        glColor3d(0.1,0.1,0.1); 
        glutSolidCube(1);  
    glPopMatrix();
    
     glPushMatrix();  // Pot  ====================================>  
        glTranslated(22.5,-1.7,0.0);  
        glScaled(0.3,3.0,2.3);  
        glColor3d(0.1,0.1,0.1); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // Pot  ====================================>  
        glTranslated(23.5,-3.1,0.0);  
        glScaled(2.3,0.3,2.3);  
        glColor3d(0.1,0.1,0.1); 
        glutSolidCube(1);  
    glPopMatrix();
	 
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,0.0);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,0.0);  
        glRotated(7,10,0,-4);  
        glScaled(0.1,3.0,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,0.0);  
        glRotated(7,10,0,7);  
        glScaled(0.1,2.8,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,0.0);  
        glRotated(-6,10,0,5);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,0.0);  
        glRotated(-6,10,0,-6);  
        glScaled(0.1,2.9,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,0.0);  
        glRotated(12,10,0,-7);  
        glScaled(0.1,3.1,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,0.0);  
        glRotated(12,10,0,8);  
        glScaled(0.1,3.0,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,0.0);  
        glRotated(-14,10,0,-5);  
        glScaled(0.1,2.7,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,0.0);  
        glRotated(-14,10,0,9);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
//BATAS POT  

//tempat buku ruang keluarga
	glPushMatrix();  // bagian 1  ===========================================>  
        glTranslated(7.9,0.4,-0.7);  
        glScaled(13.0,0.5,2.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();

	glPushMatrix();  // bagian 2 ===========================================>  
        glTranslated(6.1,2.7,-0.7);  
        glScaled(10.0,0.5,2.4);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // bagian 3  ===========================================>  
        glTranslated(4.6,5.0,-0.7);  
        glScaled(7.0,0.5,2.4);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // bagian 4  ===========================================>  
        glTranslated(3.6,7.3,-0.7);  
        glScaled(5.0,0.5,2.4);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // bagian samping  ===========================================>  
        glTranslated(1.3,4.1,-0.7);  
        glScaled(0.5,6.9,2.4);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
//batas
//Meja di bawah pojokan buku ruangan
	glPushMatrix();  // bagian bawah  ===========================================>  
        glTranslated(7.9,-3.0,-0.7);  
        glScaled(13.0,0.5,2.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
     glPushMatrix();  // bagian samping kanan  ===========================================>  
        glTranslated(1.3,-1.3,-0.7);  
        glScaled(0.5,3.9,2.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // bagian samping kanan  ===========================================>  
        glTranslated(14.5,-1.3,-0.7);  
        glScaled(0.5,3.9,2.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // bagian dalam 1  ===========================================>  
        glTranslated(10.5,-1.3,-0.7);  
        glScaled(0.5,3.9,2.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // bagian dalam 2 ===========================================>  
        glTranslated(5.5,-1.3,-0.7);  
        glScaled(0.5,3.9,2.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // bagian dibuka 1  ===========================================>  
        glTranslated(3.4,-1.3,0.7);  
        glScaled(3.8,2.9,0.3);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);   
    glPopMatrix();
    
     glPushMatrix();  // bagian dibuka 2  ===========================================>  
        glTranslated(8.0,-1.3,0.7);  
        glScaled(4.5,2.9,0.3);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // bagian dibuka 3  ===========================================>  
        glTranslated(12.5,-1.3,0.7);  
        glScaled(3.5,2.9,0.3);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);   
    glPopMatrix();
      
    glPushMatrix();  // pojok pegangan 1  ===========================================>  
        glTranslated(4.7,-1.3,0.7);  
        glScaled(0.2,1.5,0.4);  
        glColor3d(1.1,1.1,1.1);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // pojok pegangan 2 ===========================================>  
        glTranslated(9.7,-1.3,0.7);  
        glScaled(0.2,1.5,0.4);  
        glColor3d(1.1,1.1,1.1);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // pojok pegangan 3 ===========================================>  
        glTranslated(13.7,-1.3,0.7);  
        glScaled(0.2,1.5,0.4);  
        glColor3d(1.1,1.1,1.1);  
        glutSolidCube(1);   
    glPopMatrix();
    
    
//Buku dipojokkan
	glPushMatrix();  // buku  ===========================================>  
        glTranslated(1.8,6.1,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.6,0.3,0.2);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(2.3,6.1,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(1.0,0.8,0.1);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(2.8,6.1,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.1,0.9,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(3.3,6.1,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.2,0.3,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(3.8,6.1,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(1.0,0.7,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(4.3,6.1,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(1.0,0.6,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(4.8,6.1,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(1.0,0.5,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(5.3,6.1,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(1.0,0.2,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(5.8,6.1,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(1.0,0.3,0.6);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // bola  ===========================================>  
        glTranslated(7.3,6.2,-0.6);  
        glScaled(1.0,1.0,1.0);  
        glColor3d(1.0,0.3,0.6);  
        glutSolidSphere(1,slices,stacks);    
    glPopMatrix();
    
    //bagian 1
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(1.8,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.9,0.9,0.9);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(2.3,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.5,0.9,0.9);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(2.8,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.9,0.0,0.8);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(3.3,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.9,0.9,0.8);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(3.8,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.6,0.2,0.7);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(4.3,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.6,0.3,0.2);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(4.8,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.6,0.5,0.2);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(5.3,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.5,0.6,0.5);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(5.8,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.2,0.3,0.5);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(6.3,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.6,0.1,0.5);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(6.8,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.4,0.6,0.5);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(7.3,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.6,0.5,0.4);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(7.8,3.8,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.3,0.2,0.1);  
        glutSolidCube(1);   
    glPopMatrix();
    
    //bagian 2
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(1.8,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.1,0.1);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(2.3,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.4,0.2);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(2.8,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.4,0.3);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(3.3,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.6,0.4);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(3.8,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.6,0.5);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(4.3,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.7,0.6);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(4.8,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.7,0.7);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(5.3,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.8,0.8);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(5.8,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.9,0.9);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(6.3,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.0,0.1);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(6.8,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.2,0.2);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(7.3,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.2,0.3);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(7.8,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.2,0.4);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(8.3,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.2,0.5);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(8.8,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.2,0.6);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(9.3,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.2,0.7);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(9.8,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.2,0.8);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(10.3,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.2,0.9);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // buku  ===========================================>  
        glTranslated(10.8,1.5,-0.6);  
        glScaled(0.4,1.7,2.4);  
        glColor3d(0.7,0.3,0.1);  
        glutSolidCube(1);   
    glPopMatrix();
//AKHIR BUKU

//PAJANGAN
	glPushMatrix();  // pojok  ===========================================>  
        glTranslated(13.4,0.8,-0.6);  
        glScaled(2.0,0.2,2.2);  
        glColor3d(0.1,0.1,0.1);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // pojok  ===========================================>  
        glTranslated(13.4,1.4,-0.6);  
        glScaled(1.7,1.2,1.7);  
        glColor3d(0.5,0,0);  
        glutSolidCube(1);   
    glPopMatrix();

	glPushMatrix();  // pojok  ===========================================>  
        glTranslated(13.4,2.6,-0.6);  
        glScaled(1.3,1.2,1.3);  
        glColor3d(0,0.5,0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // pojok  ===========================================>  
        glTranslated(13.4,3.6,-0.6);  
        glScaled(1.0,1.2,1.0);  
        glColor3d(0,0,0.5);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // pojok  ===========================================>  
        glTranslated(13.4,4.6,-0.6);  
        glScaled(0.8,1.2,0.8);  
        glColor3d(1,0.5,0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // pojok  ===========================================>  
        glTranslated(13.4,5.6,-0.6);  
        glScaled(0.2,2.2,0.2);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // pojok  ===========================================>  
        glTranslated(13.7,6.5,-0.6);  
        glScaled(0.6,0.3,0.1);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // pojok  ===========================================>  
        glTranslated(13.7,6.2,-0.6);  
        glScaled(0.6,0.3,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
     glPushMatrix();  // pojok  ===========================================>  
        glTranslated(13.4,5.6,-0.6);  
        glScaled(0.2,2.2,0.2);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
     glPushMatrix();  //GPC ===========================================>  
        glTranslated(13.2,3.7,0.0);  
        glScaled(0.2,0.8,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  //GPC ===========================================>  
        glTranslated(13.6,3.5,0.0);  
        glScaled(0.2,0.4,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // GPC  ===========================================>  
        glTranslated(13.4,4.0,0.0);  
        glScaled(0.6,0.2,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // GPC  ===========================================>  
        glTranslated(13.4,3.3,0.0);  
        glScaled(0.6,0.2,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
     glPushMatrix();  //GPC ===========================================>  
        glTranslated(13.2,2.6,0.2);  
        glScaled(0.2,0.9,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
     glPushMatrix();  // GPC  ===========================================>  
        glTranslated(13.4,3.0,0.2);  
        glScaled(0.6,0.2,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
     glPushMatrix();  //GPC ===========================================>  
        glTranslated(13.6,2.7,0.2);  
        glScaled(0.2,0.4,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // GPC  ===========================================>  
        glTranslated(13.4,2.5,0.2);  
        glScaled(0.6,0.2,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // GPC  ===========================================>  
        glTranslated(13.4,1.8,0.4);  
        glScaled(0.6,0.2,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  //GPC ===========================================>  
        glTranslated(13.2,1.5,0.4);  
        glScaled(0.2,0.7,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
    glPushMatrix();  // GPC  ===========================================>  
        glTranslated(13.4,1.2,0.4);  
        glScaled(0.6,0.2,0.1);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);   
    glPopMatrix();
    
// Kipas Angin  
    glPushMatrix();  // Dudukan Kipas  ========================================>  
        glTranslated(7.5,-3.0,22.2);  
        glScaled(1.2,0.2,1.2);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Tombol Kipas Tengah  ==================================>  
        glTranslated(7.8,-0.9,21.8);  
        glScaled(0.1,0.1,0.1);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Tombol Kipas  =========================================>  
        glTranslated(7.8,-0.9,22.2);  
        glScaled(0.1,0.1,0.1);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Tombol Kipas Merah  ===================================>  
        glTranslated(7.8,-0.9,22.6);  
        glScaled(0.1,0.1,0.1);  
        glColor3d(1.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Tiang Kipas  ==========================================>  
        glTranslated(7.5,-1.0,22.2);  
        glScaled(0.2,3.8,0.2);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidCube(1);  
    glPopMatrix(); 
	
	glPushMatrix();  // Papan tombol  ==========================================>  
        glTranslated(7.7,-1.0,22.2);  
        glScaled(0.2,0.7,1.2);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix(); 
  
    glPushMatrix();  // Mesin Kipas  ==========================================>  
        glTranslated(7.5,1.4,22.2);  
        glScaled(0.7,0.55,0.55);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Panel  ================================================>  
        glTranslated(7.2,1.6,22.2);  
        glScaled(0.09,0.6,0.09);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // As Kipas  =============================================>  
        glTranslated(7.7,1.4,22.2);  
        glScaled(0.8,0.2,0.2);  
        glColor3d(.5,0.5,0.5);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Jaring Kipas  =========================================>  
        glTranslated(8.2,1.4,22.2);  
        glScaled(0.5,1.45,1.45);  
        glColor3d(1.0,1.0,1.0);  
        glutWireSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Baling Baling Kipas  ==================================>  
        glTranslated(8.2,1.4,22.2);  
        glRotated(RotasiKipas,1,0,0);  
        glScaled(0.08,0.3,1.3);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Baling Baling Kipas  ==================================>  
        glTranslated(8.2,1.4,22.2);  
        glRotated(RotasiKipas,1,0,0);  
        glScaled(0.08,1.3,0.3);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix(); 
	
	glPushMatrix();  // Remote Kipas ===========================================>
		glTranslated(19.5,0.1,21.8);
		glScaled(0.8,0.1,0.3);
		glColor3d(0.1,0.1,0.1);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();  // Remote Kipas ===========================================>
		glTranslated(19.2,0.1,21.8);
		glScaled(0.1,0.12,0.1);
		glColor3d(1.0,0.0,0.0);
		glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();  // Remote Kipas ===========================================>
		glTranslated(19.5,0.1,21.72);
		glScaled(0.2,0.12,0.1);
		glColor3d(1.0,1.0,1.0);
		glutSolidCube(1);
	glPopMatrix();
	
		glPushMatrix();  // Remote Kipas ===========================================>
		glTranslated(19.5,0.1,21.88);
		glScaled(0.2,0.12,0.1);
		glColor3d(1.0,1.0,1.0);
		glutSolidCube(1);
	glPopMatrix();
	
	//Bingkai
	
	glPushMatrix();  // Bingkai Pintu Sumbu Z Berdiri  ========================>  
		glTranslated(0.3,1.5,6.6);  
        glScaled(0.5,13.0,0.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Pintu Sumbu Z Berdiri  ========================>  
        glTranslated(0.3,1.5,1.4);  
        glScaled(0.5,13.0,0.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Bingkai Pintu Sumbu Z Baring  =========================>  
        glTranslated(0.3,8.3,4.0);  
        glScaled(0.5,0.6,6.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Pintu Sumbu Z Baring  =========================>  
        glTranslated(0.3,6.8,4.0);  
        glScaled(0.5,0.5,6.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	// Kamar Agun
	// Lantai  ==========================================================================>
	glPushMatrix();  // Lantai Kamar ===========================================>
	glTranslated(-12.0,-3.5,-12.5);
	glScaled(24.0,0.5,25);
	glColor3d(0.0,0.0,0.0); 
	glutSolidCube(1);
	glPopMatrix();
	
	//Karpet Putih
	glPushMatrix();  
	glTranslated(-12.0,-3.2,-12.5);
	glScaled(15.0,0.1,15);
	glColor3d(1.0,1.0,1.0); 
	glutSolidCube(1);
	glPopMatrix();
	
	//Lampu Dinding
	glPushMatrix();  // Kerucut Atas (Kiri)  =================================>  
        glTranslated(-1.0,5.9,-7.5);  
        glRotated(-90,1,0,0);  
        glScaled(1.0,1.0,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCone(1,1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Bola Hitam Tengah (Kiri)  ============================>  
        glTranslated(-1.0,5.7,-7.5);  
        glScaled(0.4,1.0,0.4);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Kotak Putih Dudukan (Kiri)  ==========================>  
        glTranslated(-0.7,5.5,-7.5);  
        glScaled(0.8,0.5,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // // Kerucut Atas (Kanan)  ===============================>  
        glTranslated(-1.0,5.9,-3.5);  
        glRotated(-90,1,0,0);  
        glScaled(1.0,1.0,1.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCone(1,1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Bola Hitam Tengah (Kanan)  =============================>  
        glTranslated(-1.0,5.7,-3.5);  
        glScaled(0.4,1.0,0.4);  
        glColor3d(0.0,0.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Kotak Putih Bawah (Kanan)  =============================>  
        glTranslated(-0.7,5.5,-3.5);  
        glScaled(0.8,0.5,0.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  

	
	//Bingkai pintu kamar
	    glPushMatrix();  // Bingkai Pintu Sumbu Z Berdiri  ========================>  
		glTranslated(0.3,1.5,-24.2);  
        glScaled(0.5,13.0,0.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Pintu Sumbu Z Berdiri  ========================>  
        glTranslated(0.3,1.5,-19.0);  
        glScaled(0.5,13.0,0.8);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Bingkai Pintu Sumbu Z Baring  =========================>  
        glTranslated(0.3,8.2,-21.6);  
        glScaled(0.5,0.5,6.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Bingkai Pintu Sumbu Z Baring  =========================>  
        glTranslated(0.3,6.8,-21.6);  
        glScaled(0.5,0.5,6.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	//Stop Kontak
	glPushMatrix();  // Dasar  ===========================>  
       	glTranslated(-0.2,4.5,-16.0);  
        glScaled(0.5,1.0,1.0);  
        glColor3d(1.0,1.0,1.0); 
        glutSolidCube(1);   
    glPopMatrix();
	
	glPushMatrix();  // Button 1  ===========================>  
       	glTranslated(-0.4,4.5,-16.2);  
        glScaled(0.5,0.5,0.1);  
        glColor3d(0.0,0.0,0.0); 
        glutSolidCube(1);   
    glPopMatrix();
	
	glPushMatrix();  // Button 2  ===========================>  
       	glTranslated(-0.4,4.5,-15.8);  
        glScaled(0.5,0.5,0.1);  
        glColor3d(0.0,0.0,0.0); 
        glutSolidCube(1);   
    glPopMatrix();  
        
	//Pintu Kamar 
	glPushMatrix();  // Pintu 1 ===============================================>  
        glTranslated(0.2,1.5,-21.5);  
        glScaled(0.5,10.0,4.5);    
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Textur 1 Dari Atas  ===========================>  
        glTranslated(0.2,5.0,-21.5);  
        glScaled(1.0,1.0,3.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Textur 2 Dari Atas  ===========================>  
       	glTranslated(0.2,3.0,-21.5);  
        glScaled(1.0,1.0,3.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);   
    glPopMatrix();  
      
    glPushMatrix();  // Pintu 1 Textur 3 Dari Atas  ===========================>    
        glTranslated(0.2,0.5,-21.5);  
        glScaled(1.0,1.0,3.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1); 
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Textur 4 Dari Atas  ===========================>  
        glTranslated(0.2,-1.5,-21.5);  
        glScaled(1.0,1.0,3.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);   
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Textur Tengah  ================================>  
        glTranslated(0.2,1.75,-21.5);  
        glScaled(1.0,1.0,2.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Pintu 1 As Pegangan ===================================>  
        glTranslated(0.0,1.75,-19.95);  
        glScaled(1.0,0.3,0.3);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidCube(1);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Lingkaran Pegangan ============================>  
        glTranslated(0.0,1.75,-19.95);  
        glScaled(0.4,0.4,0.4);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Lingkaran Genggaman Dalam =====================>  
        glTranslated(0.0,1.75,-20.06); 
        glScaled(0.3,0.3,0.2);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Pintu 1 Lingkaran Genggaman Luar ======================>  
        glTranslated(0.65,1.75,-20.06);  
        glScaled(0.2,0.3,0.3);  
        glColor3d(0.3,0.3,0.3);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  


	// Kasur di Kamar
    glPushMatrix();  // Dudukan Dipan  ========================================>  
        glTranslated(-9.0,-2.5,-5.5);  
        glScaled(14.5,0.5,9.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
    
	glPushMatrix();  // Dipan  ================================================>  
        glTranslated(-8.75,-2.3,-5.5);  
        glScaled(15.5,0.5,10.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // Sandaran  =============================================>  
        glTranslated(-0.75,-0.6,-5.5);  
        glScaled(0.5,3.8,10.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // Motif Lingkaran  ======================================>  
        glTranslated(-0.7,0.0,-5.5);  
        glScaled(0.5,1.2,5.0);  
        glColor3d(1.0,0.6,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();
    
    glPushMatrix();  // Motif Kotak Kanan  ====================================>  
        glTranslated(-0.8,-0.6,-1.8);  
        glScaled(0.7,3.0,1.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // Motif Kotak Kiri  =====================================>  
        glTranslated(-0.8,-0.6,-9.4);  
        glScaled(0.7,3.0,1.0);  
        glColor3d(1.0,0.5,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // Kasur Biru Baris 1 ===================================>  
        glTranslated(-8.75,-1.8,-2.3);  
        glScaled(14.5,1.2,3.5);  
        glColor3d(0.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // Kasur Putih Baris 2 ===================================>  
        glTranslated(-8.75,-1.8,-5.6);  
        glScaled(14.5,1.2,3.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // Kasur Biru Baris 3 ===================================>  
        glTranslated(-8.75,-1.8,-8.8);  
        glScaled(14.5,1.2,3.3);  
        glColor3d(0.0,1.0,1.0); 
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // Bantal Biru  =========================================>  
        glTranslated(-3.7,-0.8,-6.0);  
        glScaled(2.0,0.7,3.0);  
        glColor3d(0.0,1.0,1.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();
	
	glPushMatrix();  // Selimut Putih  ========================================>  
        glTranslated(-13.7,-1.0,-5.5);  
        glScaled(2.5,0.4,8.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	//lemari 	
	glPushMatrix();  // dasar lemari  ========================================>  
        glTranslated(-19.5,1.5,-22.4);  
        glScaled(9.0,9.0,4.0);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // pintu lemari 1  ========================================>  
        glTranslated(-17.5,1.5,-20.5);  
        glScaled(3.5,8.0,0.5);  
        glColor3d(1.0,1.0,1.0); 
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // pintu lemari 2  ========================================>  
        glTranslated(-21.5,1.5,-20.5);  
        glScaled(3.5,8.0,0.5);  
        glColor3d(1.0,1.0,1.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // pengangan pintu lemari 1  ========================================>  
        glTranslated(-18.0,1.5,-20.2);  
        glScaled(0.4,1.0,0.2);  
        glColor3d(1.0,0.4,0.0); 
        glutSolidCube(1);  
    glPopMatrix(); 
	
	glPushMatrix();  // pengangan pintu lemari 2  ========================================>  
        glTranslated(-20.5,1.5,-20.2);  
        glScaled(0.4,1.0,0.2);  
        glColor3d(1.0,0.4,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    //Kaca
    glPushMatrix();  // bingkai kaca  ========================================>  
        glTranslated(-21.0,3.5,-0.2);  
        glScaled(3.5,3.5,0.2);  
        glColor3d(0.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // kaca  ========================================>  
        glTranslated(-21.1,3.5,-0.4);  
        glScaled(3.0,3.0,0.1);  
        glColor3d(1.0,1.0,1.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    //Air Conditioner
    glPushMatrix();  // box  ========================================>  
        glTranslated(-12.0,7.5,-0.2);  
        glScaled(3.5,1.5,1.0);  
        glColor3d(1.0,1.0,1.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // line box  ========================================>  
        glTranslated(-12.0,7.2,-0.8);  
        glScaled(3.0,0.1,0.0);  
        glColor3d(0.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // line box  ========================================>  
        glTranslated(-12.0,7.0,-0.8);  
        glScaled(3.0,0.1,0.0);  
        glColor3d(0.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    // Pot Tumbuhan  
    glPushMatrix();  // Kotak Putih Bawah  ====================================>  
        glTranslated(-1.0,-3.0,-13.5);  
        glScaled(2.0,0.6,2.0);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Kotak Putih Atas  =====================================>  
        glTranslated(-1.0,-1.05,-13.5);  
        glScaled(1.5,0.3,1.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();  
      
    glPushMatrix();  // Bola coklat Tengah  ====================================>  
        glTranslated(-1.0,-2.05,-13.5);  
        glScaled(0.9,1.2,0.9);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-1.0,-0.3,-13.5);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-1.0,-0.3,-13.5);  
        glRotated(7,10,0,-4);  
        glScaled(0.1,3.0,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-1.0,-0.3,-13.5);  
        glRotated(7,10,0,7);  
        glScaled(0.1,2.8,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-1.0,-0.3,-13.5);  
        glRotated(-6,10,0,5);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-1.0,-0.3,-13.5);  
        glRotated(-6,10,0,-6);  
        glScaled(0.1,2.9,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-1.0,-0.3,-13.5);  
        glRotated(12,10,0,-7);  
        glScaled(0.1,3.1,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-1.0,-0.3,-13.5);  
        glRotated(12,10,0,8);  
        glScaled(0.1,3.0,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-1.0,-0.3,-13.5);  
        glRotated(-14,10,0,-5);  
        glScaled(0.1,2.7,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(-1.0,-0.3,-13.5);  
        glRotated(-14,10,0,9);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  

	//Meja	
	glPushMatrix();  // atap meja  ========================================>  
        glTranslated(-20.1,0.5,-2.0);  
        glScaled(5.5,0.5,3.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // Kaki meja 1  ========================================>  
        glTranslated(-17.7,-1.5,-0.6);  
        glScaled(0.5,3.5,0.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // Kaki meja 1.1  ========================================>  
        glTranslated(-17.7,-1.5,-3.5);  
        glScaled(0.5,3.5,0.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // Kaki meja 2  ========================================>  
        glTranslated(-22.5,-1.5,-0.6);  
        glScaled(0.5,3.5,0.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	glPushMatrix();  // Kaki meja 2.1  ========================================>  
        glTranslated(-22.5,-1.5,-3.5);  
        glScaled(0.5,3.5,0.5);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
	
	//Kursi 
	glPushMatrix();  // alas  ========================================>  
        glTranslated(-20.0,-2.3,-5.5);  
        glScaled(3.5,1.9,2.0);  
        glColor3d(1.0,0.4,0.0);  
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // busa  ========================================>  
        glTranslated(-20.1,-1.3,-5.5);  
        glScaled(2.5,0.1,1.5);  
        glColor3d(1.0,1.0,1.0);  
        glutSolidCube(1);  
    glPopMatrix();


	// Lantai Dapur  ==========================================================================>

	glPushMatrix();  
	glTranslated(12.5,-3.5,-18.3);
	glScaled(25.0,0.5,32.5);
	glColor3d(0.0,0.0,0.0);
	glutSolidCube(1);
	glPopMatrix();
	
	// perabot dapur  ================================================================================>

//kursi1
glPushMatrix(); //kaki pajang1 
glTranslated(20.0,0.0,-15.0);
glScaled(0.3,7.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pajang2 
glTranslated(20.0,0.0,-17.0);
glScaled(0.3,7.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pantat kursi
glTranslated(18.5,-0.5,-16.0);
glScaled(3.0,0.3,3.0);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pendek1 
glTranslated(17.5,-2.0,-17.0);
glScaled(0.3,3.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pendek2 
glTranslated(17.5,-2.0,-15.0);
glScaled(0.3,3.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //sandaran
glTranslated(19.7,2.5,-16.0);
glScaled(0.3,1.5,3.0);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

//kursi2
glPushMatrix(); //kaki pajang1 
glTranslated(20.0,0.0,-22.0);
glScaled(0.3,7.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pajang2 
glTranslated(20.0,0.0,-24.0);
glScaled(0.3,7.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pantat kursi
glTranslated(18.5,-0.5,-23.0);
glScaled(3.0,0.3,3.0);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pendek1 
glTranslated(17.5,-2.0,-24.0);
glScaled(0.3,3.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pendek2 
glTranslated(17.5,-2.0,-22.0);
glScaled(0.3,3.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //sandaran
glTranslated(19.7,2.5,-23.0);
glScaled(0.3,1.5,3.0);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

//meja makan
glPushMatrix(); //alasmeja
glTranslated(15.0,1.5,-19.5);
glScaled(8.0,0.5,13.0);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //poci
glTranslated(15.0,2.55,-19.5);
glScaled(1.0,1.0,1.0);
glColor3d(0.8,0.8,0.8);
glutSolidTeapot(1);
glPopMatrix();


glPushMatrix(); //kakibawah1
glTranslated(15.0,-3.0,-24.5);
glScaled(6.0,0.5,0.5);
glColor3d(0.0,0.1,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kakibawah2
glTranslated(15.0,-3.0,-14.5);
glScaled(6.0,0.5,0.5);
glColor3d(0.0,0.1,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kakimeja1
glTranslated(15.0,-1.0,-14.5);
glScaled(0.5,4.5,0.5);
glColor3d(0.0,0.1,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kakimeja2
glTranslated(15.0,-1.0,-24.5);
glScaled(0.5,4.5,0.5);
glColor3d(0.0,0.1,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kakibawah hz
glTranslated(15.0,-3.0,-19.5);
glScaled(0.5,0.5,10.0);
glColor3d(0.0,0.1,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //piring1
glTranslated(17.5,1.7,-16.0);
glScaled(1.0,0.1,1.0);
glColor3d(1.0,1.0,1.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

glPushMatrix(); //piring2
glTranslated(17.5,1.7,-23.0);
glScaled(1.0,0.1,1.0);
glColor3d(1.0,1.0,1.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

glPushMatrix(); //piring3
glTranslated(12.5,1.7,-23.0);
glScaled(1.0,0.1,1.0);
glColor3d(1.0,1.0,1.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

glPushMatrix(); //piring4
glTranslated(12.5,1.7,-16.0);
glScaled(1.0,0.1,1.0);
glColor3d(1.0,1.0,1.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();



//kursi3
glPushMatrix(); //kaki pajang1 
glTranslated(10.0,0.0,-22.0);
glScaled(0.3,7.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pajang2 
glTranslated(10.0,0.0,-24.0);
glScaled(0.3,7.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pantat kursi
glTranslated(11.5,-0.5,-23.0);
glScaled(3.0,0.3,3.0);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pendek1 
glTranslated(12.5,-2.0,-24.0);
glScaled(0.3,3.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pendek2 
glTranslated(12.5,-2.0,-22.0);
glScaled(0.3,3.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //sandaran
glTranslated(10.3,2.5,-23.0);
glScaled(0.3,1.5,3.0);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

//kursi4
glPushMatrix(); //kaki pajang1 
glTranslated(10.0,0.0,-15.0);
glScaled(0.3,7.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pajang2 
glTranslated(10.0,0.0,-17.0);
glScaled(0.3,7.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pantat kursi
glTranslated(11.5,-0.5,-16.0);
glScaled(3.0,0.3,3.0);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pendek1 
glTranslated(12.5,-2.0,-17.0);
glScaled(0.3,3.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kaki pendek2 
glTranslated(12.5,-2.0,-15.0);
glScaled(0.3,3.0,0.3);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //sandaran
glTranslated(10.3,2.5,-16.0);
glScaled(0.3,1.5,3.0);
glColor3d(0.2,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

//buffett kompor

glPushMatrix(); //bawah===============
glTranslated(7.5,-1.2,-4.5);
glScaled(15.0,4.0,4.0);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pintu1
glTranslated(12.5,-1.2,-6.6);
glScaled(5.0,3.6,0.3);
glColor3d(0.0,0.5,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //gagangpintu1
glTranslated(10.5,-1.2,-6.8);
glScaled(0.5,0.9,0.1);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pintu2
glTranslated(7.0,-1.2,-6.6);
glScaled(5.0,3.6,0.3);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //gagangpintu2
glTranslated(5.0,-1.2,-6.8);
glScaled(0.5,0.9,0.1);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //kompor
glTranslated(7.0,1.6,-4.6);
glScaled(5.0,0.6,3.0);
glColor3d(0.5,0.5,0.5);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //sumbu kompor
glTranslated(8.5,1.9,-4.6);
glScaled(0.6,0.1,0.6);
glColor3d(0.0,0.0,0.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

glPushMatrix(); //sumbu kompor
glTranslated(5.5,1.9,-4.6);
glScaled(0.6,0.1,0.6);
glColor3d(0.0,0.0,0.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

glPushMatrix(); //kontak kompor
glTranslated(8.5,1.6,-6.15);
glScaled(0.2,0.2,0.1);
glColor3d(0.0,0.0,0.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

glPushMatrix(); //kontak kompor
glTranslated(5.5,1.6,-6.15);
glScaled(0.2,0.2,0.1);
glColor3d(0.0,0.0,0.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

glPushMatrix(); //atas================
glTranslated(12.7,7.0,-4.5);
glScaled(4.0,4.0,4.0);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pintuatas
glTranslated(12.7,7.0,-6.5);
glScaled(3.6,3.6,0.3);
glColor3d(0.0,0.5,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //gagangpintu
glTranslated(11.5,7.0,-6.7);
glScaled(0.5,0.9,0.1);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();




//buffet cuci

glPushMatrix(); //wastfle
glTranslated(2.2,1.0,-12.5);
glScaled(3.4,0.0,6.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //air
glTranslated(2.2,1.01,-13.8);
glScaled(3.0,0.0,3.0);
glColor3d(0.0,0.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pipa
glTranslated(0.5,1.01,-13.8);
glScaled(0.2,3.0,0.2);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pipa nonjol
glTranslated(0.8,2.3,-13.8);
glScaled(1.6,0.2,0.2);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //atas==================
glTranslated(2.2,7.0,-9.5);
glScaled(4.0,4.0,15.0);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pintu1
glTranslated(4.3,7.0,-4.9);
glScaled(0.3,3.6,4.3);
glColor3d(0.0,0.5,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //gagangpintu1
glTranslated(4.5,7.0,-6.5);
glScaled(0.1,0.9,0.5);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pintu2
glTranslated(4.3,7.0,-9.55);
glScaled(0.3,3.6,4.3);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //gagangpintu2
glTranslated(4.5,7.0,-11.2);
glScaled(0.1,0.9,0.5);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pintu3
glTranslated(4.3,7.0,-14.2);
glScaled(0.3,3.6,4.3);
glColor3d(0.0,0.5,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //gagangpintu3
glTranslated(4.5,7.0,-15.8);
glScaled(0.1,0.9,0.5);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();


glPushMatrix(); //bawah
glTranslated(2.2,-1.2,-9.5);
glScaled(4.0,4.0,15.0);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pintu1
glTranslated(4.3,-1.2,-9.55);
glScaled(0.3,3.6,4.3);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //gagangpintu1
glTranslated(4.5,-1.25,-11.2);
glScaled(0.1,0.9,0.5);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pintu2
glTranslated(4.3,-1.2,-14.2);
glScaled(0.3,3.6,4.3);
glColor3d(0.0,0.5,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //gagangpintu2
glTranslated(4.5,-1.25,-15.8);
glScaled(0.1,0.9,0.5);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();


//karpet

glPushMatrix();
glTranslated(15.0,-3.2,-19.5);
glScaled(13.0,0.1,18.0);
glColor3d(0.5,0.5,0.5);
glutSolidCube(1);
glPopMatrix();

//kulkas

glPushMatrix(); //badan
glTranslated(22.0,0.3,-32.5);
glScaled(4.0,8.0,3.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pintu bawah
glTranslated(22.0,-1.1,-31.0);
glScaled(3.5,4.0,0.4);
glColor3d(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //gagang pintu bawah
glTranslated(20.8,-1.1,-30.8);
glScaled(0.1,1.8,0.3);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //pintu atas
glTranslated(22.0,2.6,-31.0);
glScaled(3.5,3.0,0.4);
glColor3d(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix(); //gagang pintu atas
glTranslated(20.8,2.5,-30.8);
glScaled(0.1,1.3,0.3);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

//POT TANAMAN
    glPushMatrix();  // Pot  ====================================>  
        glTranslated(23.5,-1.7,-4.0);  
        glScaled(2.0,2.7,2.0);  
        glColor3d(0.5,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // Pot  ====================================>  
        glTranslated(23.5,-1.7,-5.1);  
        glScaled(2.3,3.0,0.3);  
        glColor3d(0.1,0.1,0.1); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // Pot  ====================================>  
        glTranslated(23.5,-1.7,-3.0);  
        glScaled(2.3,3.0,0.3);  
        glColor3d(0.1,0.1,0.1); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // Pot  ====================================>  
        glTranslated(24.5,-1.7,-4.0);  
        glScaled(0.3,3.0,2.3);  
        glColor3d(0.1,0.1,0.1); 
        glutSolidCube(1);  
    glPopMatrix();
    
     glPushMatrix();  // Pot  ====================================>  
        glTranslated(22.5,-1.7,-4.0);  
        glScaled(0.3,3.0,2.3);  
        glColor3d(0.1,0.1,0.1); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // Pot  ====================================>  
        glTranslated(23.5,-3.1,-4.0);  
        glScaled(2.3,0.3,2.3);  
        glColor3d(0.1,0.1,0.1); 
        glutSolidCube(1);  
    glPopMatrix();
	 
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,-4.0);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
  
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,-4.0);  
        glRotated(7,10,0,-4);  
        glScaled(0.1,3.0,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,-4.0);  
        glRotated(7,10,0,7);  
        glScaled(0.1,2.8,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,-4.0);  
        glRotated(-6,10,0,5);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,-4.0);  
        glRotated(-6,10,0,-6);  
        glScaled(0.1,2.9,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,-4.0);  
        glRotated(12,10,0,-7);  
        glScaled(0.1,3.1,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,-4.0);  
        glRotated(12,10,0,8);  
        glScaled(0.1,3.0,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,-4.0);  
        glRotated(-14,10,0,-5);  
        glScaled(0.1,2.7,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
      
    glPushMatrix();  // Daun Hijau  ===========================================>  
        glTranslated(23.5,-0.3,-4.0);  
        glRotated(-14,10,0,9);  
        glScaled(0.1,3.2,0.1);  
        glColor3d(0.0,1.0,0.0);  
        glutSolidSphere(1,slices,stacks);  
    glPopMatrix();  
    
    //tirai
    
    glPushMatrix();  // kusen atas
        glTranslated(19.0,8.5,-2.2);  
        glScaled(6.0,0.5,0.6);  
        glColor3d(1.0,1.0,1.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
        glPushMatrix();  // kusen kanan
        glTranslated(21.8,2.7,-2.2);  
        glScaled(0.5,12.1,0.6);  
        glColor3d(1.0,1.0,1.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
       glPushMatrix();  // kusen kiri
        glTranslated(15.8,2.7,-2.2);  
        glScaled(0.5,12.1,0.6);  
        glColor3d(1.0,1.0,1.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // besihorden
        glTranslated(19.0,8.5,-2.6);  
        glScaled(5.7,0.2,0.3);  
        glColor3d(1.0,1.0,1.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
        glPushMatrix();  // benang horden
        glTranslated(21.4,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
            glPushMatrix();  // benang horden
        glTranslated(21.2,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
             glPushMatrix();  // benang horden
        glTranslated(21.0,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
             glPushMatrix();  // benang horden
        glTranslated(20.8,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
             glPushMatrix();  // benang horden
        glTranslated(20.6,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
             glPushMatrix();  // benang horden
        glTranslated(20.4,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
             glPushMatrix();  // benang horden
        glTranslated(20.2,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
             glPushMatrix();  // benang horden
        glTranslated(20.0,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
             glPushMatrix();  // benang horden
        glTranslated(19.8,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(19.6,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(19.4,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();

glPushMatrix();  // benang horden
        glTranslated(19.2,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(19.0,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(18.8,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
        glPushMatrix();  // benang horden
        glTranslated(18.6,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
        glPushMatrix();  // benang horden
        glTranslated(18.4,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
        glPushMatrix();  // benang horden
        glTranslated(18.2,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
        glPushMatrix();  // benang horden
        glTranslated(18.0,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(17.8,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(17.6,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(17.4,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(17.2,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(17.0,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(16.8,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(16.6,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(16.4,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    
    glPushMatrix();  // benang horden
        glTranslated(16.2,3.6,-2.6);  
        glScaled(0.05,10.0,0.05);  
        glColor3d(1.0,0.0,0.0); 
        glutSolidCube(1);  
    glPopMatrix();
    


//tanaman=============================

//batas dapur=====================================================================================================>


// Bagian Kamar Kiri Tengah ===================================================================================>

// Tembok ===========================================================================>

glPushMatrix();  // Tembok Hitam Sumbu X  ===========================>
glTranslated(-12.0,-1.0,-24.8);
glScaled(24.0,5.0,0.5);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Tembok Putih Sumbu X  ===========================>
glTranslated(-12.0,2.0,-24.8);
glScaled(24.0,1.0,0.5);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Tembok Merah Sumbu X  ===========================>
glTranslated(-12.0,6.0,-24.8);
glScaled(24.0,7.0,0.5);
glColor3d(0.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Tembok Hitam Sumbu Z  ===========================>
glTranslated(0.2,-1.0,-34.0);
glScaled(0.5,5.0,1.0);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Tembok Putih Sumbu Z  ===========================>
glTranslated(0.2,2.0,-34.0);
glScaled(0.5,1.0,1.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Tembok Merah Sumbu Z  ===========================>
glTranslated(0.2,6.0,-34.0);
glScaled(0.5,7.0,1.0);
glColor3d(0.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Tembok Biru WC Sumbu Z Atas  ============================>
glTranslated(0.2,9.0,-30.4);
glScaled(0.5,1.0,6.5);
glColor3d(0.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

// Lantai WC  ==========================================================================>

	glPushMatrix();  
	glTranslated(-12.0,-3.5,-29.5);
	glScaled(24.0,0.5,10.0);
	glColor3ub(255, 255, 255);
	glutSolidCube(1);
	glPopMatrix();
	
	// Lantai  ==========================================================================>

glPushMatrix();  // Ubin Dasar Kiri Belakang ===========================================>
glTranslated(-12.0,-3.5,-29.5);
glScaled(24.0,0.5,10.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

// Kloset ==========================================================================>

glPushMatrix();  // Kloset belakang ===========================================>
glTranslated(-22.5,-1.0,-26.5);
glScaled(3.0,5.0,3.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Kloset bawah===========================================>
glTranslated(-19.5,-2.5,-26.5);
glScaled(3.0,2.5,3.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Kloset atas===========================================>
glTranslated(-19.0,-1.0,-26.5);
glScaled(4.0,0.5,3.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Kloset belakang ===========================================>
glTranslated(-22.5,1.5,-26.5);
glScaled(0.5,0.1,0.5);
glColor3d(0.0,0.0,0.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

glPushMatrix();  // Kloset belakang ===========================================>
glTranslated(-22.5,1.55,-26.5);
glScaled(0.3,0.1,0.3);
glColor3d(1.0,1.0,1.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

// Gantungan Baju ==========================================================================>

glPushMatrix();  // papan ===========================================>
glTranslated(-5.5,6.0,-25.3);
glScaled(6.0,1.0,0.5);
glColor3d(1.0,1.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // gantungan ===========================================>
glTranslated(-5.5,6.0,-26.0);
glScaled(0.3,0.3,0.3);
glColor3d(1.0,1.0,0.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

glPushMatrix();  // gantungan ===========================================>
glTranslated(-3.5,6.0,-26.0);
glScaled(0.3,0.3,0.3);
glColor3d(1.0,1.0,0.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

glPushMatrix();  // gantungan ===========================================>
glTranslated(-7.5,6.0,-26.0);
glScaled(0.3,0.3,0.3);
glColor3d(1.0,1.0,0.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

// Bak Air ==========================================================================>

glPushMatrix();  // Bak ===========================================>
glTranslated(-21.5,-1.8,-32.5);
glScaled(5.0,3.0,4.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Air ===========================================>
glTranslated(-21.5,0.0,-32.5);
glScaled(4.0,0.5,3.0);
glColor3d(0.0,0.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Bak Atas ===========================================>
glTranslated(-21.5,0.0,-34.2);
glScaled(5.0,1.0,0.6);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Bak Atas ===========================================>
glTranslated(-21.5,0.0,-30.8);
glScaled(5.0,1.0,0.6);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Bak Atas ===========================================>
glTranslated(-19.3,0.0,-32.5);
glScaled(0.6,1.0,3.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Bak Atas ===========================================>
glTranslated(-23.7,0.0,-32.5);
glScaled(0.6,1.0,3.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

// Tissue Toilet ==========================================================================>

glPushMatrix();  // Tiang ===========================================>
glTranslated(-16.0,3.0,-25.3);
glScaled(0.2,0.2,0.6);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Tiang ===========================================>
glTranslated(-15.0,3.0,-25.3);
glScaled(0.2,0.2,0.6);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // tissue ===========================================>
glTranslated(-15.5,3.0,-25.5);
glScaled(0.5,0.2,0.1);
glColor3d(1.0,1.0,1.0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();

// Sibur ==========================================================================>

glPushMatrix();  // Sibur ===========================================>
glTranslated(-19.5,1.0,-31.0);
glScaled(1.0,1.0,1.0);
glColor3d(0.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Sibur ===========================================>
glTranslated(-19.5,1.48,-31.0);
glScaled(0.8,0.1,0.8);
glColor3d(0.0,0.0,0.0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();  // Sibur ===========================================>
glTranslated(-19.5,1.4,-30.0);
glScaled(0.3,0.3,1.0);
glColor3d(0.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

// Keset ==========================================================================>

glPushMatrix();  // Ubin Dasar Kiri Belakang ===========================================>
glTranslated(3.0,-3.2,-30.5);
glScaled(3.0,0.1,5.0);
glColor3d(1.0,1.0,1.0);
glutSolidCube(1);
glPopMatrix();

// Pintu ==========================================================================>

//Bingkai pintu kamar
	    glPushMatrix();  // Bingkai Pintu Sumbu Z Berdiri  ========================>
		glTranslated(0.3,1.53,-33.1);
        glScaled(0.5,13.0,0.8);
        glColor3d(1.0,1.0,1.0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Bingkai Pintu Sumbu Z Berdiri  ========================>
        glTranslated(0.3,1.53,-27.9);
        glScaled(0.5,13.0,0.8);
        glColor3d(1.0,1.0,1.0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Bingkai Pintu Sumbu Z Baring  =========================>
        glTranslated(0.3,8.23,-30.5);
        glScaled(0.5,0.5,6.0);
        glColor3d(1.0,1.0,1.0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Bingkai Pintu Sumbu Z Baring  =========================>
        glTranslated(0.3,6.8,-30.5);
        glScaled(0.5,0.5,6.0);
        glColor3d(1.0,1.0,1.0);
        glutSolidCube(1);
    glPopMatrix();

	glPushMatrix();  // Pintu 1 ===============================================>
        glTranslated(0.2,1.52,-30.5);
        glScaled(0.5,10.0,4.5);
        glColor3d(1.0,0.4,0.0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Pintu 1 Textur 1 Dari Atas  ===========================>
        glTranslated(0.2,5.0,-30.5);
        glScaled(1.0,1.0,3.0);
        glColor3d(1.0,0.5,0.0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Pintu 1 Textur 2 Dari Atas  ===========================>
       	glTranslated(0.2,3.0,-30.5);
        glScaled(1.0,1.0,3.0);
        glColor3d(1.0,0.5,0.0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Pintu 1 Textur 3 Dari Atas  ===========================>
        glTranslated(0.2,0.5,-30.5);
        glScaled(1.0,1.0,3.0);
        glColor3d(1.0,0.5,0.0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Pintu 1 Textur 4 Dari Atas  ===========================>
        glTranslated(0.2,-1.5,-30.5);
        glScaled(1.0,1.0,3.0);
        glColor3d(1.0,0.5,0.0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Pintu 1 Textur Tengah  ================================>
        glTranslated(0.2,1.75,-30.5);
        glScaled(1.0,1.0,2.0);
        glColor3d(1.0,0.5,0.0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Pintu 1 As Pegangan ===================================>
        glTranslated(0.0,1.75,-28.95);
        glScaled(1.0,0.3,0.3);
        glColor3d(0.3,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();  // Pintu 1 Lingkaran Pegangan ============================>
        glTranslated(0.0,1.75,-28.95);
        glScaled(0.4,0.4,0.4);
        glColor3d(0.3,0.3,0.3);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();  // Pintu 1 Lingkaran Genggaman Dalam =====================>
        glTranslated(0.0,1.75,-29.06);
        glScaled(0.3,0.3,0.2);
        glColor3d(0.3,0.3,0.3);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();  // Pintu 1 Lingkaran Genggaman Luar ======================>
        glTranslated(0.65,1.75,-29.06);
        glScaled(0.2,0.3,0.3);
        glColor3d(0.3,0.3,0.3);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

	glutSwapBuffers();
	glutPostRedisplay();                                    // Redisplay Screen
}


void keyboard( unsigned char key, int x, int y ) {          // Pada Keyboard
	switch ( key ) {                                        // Inisialisasi Keyboard
		case 27:                                            // Jika ESC D tekan
			exit( 0 );                                      // Tutup Program
		break;                                                  
	}
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

	glutCreateWindow ("Kelompok Saling Percaya");

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


