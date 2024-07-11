#include <GL/glut.h> 
#include<math.h> 
#include<stdio.h> 
// Rectangle parameters 
GLfloat rectWidth = 100.0; 
GLfloat rectHeight = 50.0; 
GLfloat rectPosX = 0.0; 
GLfloat rectPosY = 0.0; 
// Rotation angle 
GLfloat rotationAngle = 0.0; 
// Scaling factors 
GLfloat scaleX = 1.0; 
GLfloat scaleY = 1.0; 
void drawRectangle() { 
glPushMatrix(); 
// Apply translation 
glTranslatef(rectPosX, rectPosY, 0.0); 
// Apply rotation 
glRotatef(rotationAngle, 0.0, 0.0, 1.0); 
// Apply scaling 
glScalef(scaleX, scaleY, 1.0); 
// Draw rectangle 
glBegin(GL_QUADS); 
glColor3f(1.0, 0.0, 0.0); // Red color 
glVertex2f(-rectWidth / 2, -rectHeight / 2); 
glVertex2f(rectWidth / 2, -rectHeight / 2); 
glVertex2f(rectWidth / 2, rectHeight / 2); 
glVertex2f(-rectWidth / 2, rectHeight / 2); 
glEnd(); 
glPopMatrix(); 
} 
void display() { 
glClear(GL_COLOR_BUFFER_BIT); 
glLoadIdentity(); 
// Draw rectangle 
drawRectangle(); 
glFlush(); 
} 
void reshape(int w, int h) { 
glViewport(0, 0, w, h); 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1.0, 1.0); 
glMatrixMode(GL_MODELVIEW); 
glLoadIdentity(); 
} 
void keyboard(unsigned char key, int x, int y) { 
switch (key) { 
  case 'w': 
  rectPosY += 10.0; // Move rectangle up 
  break; 
  case 's': 
  rectPosY -= 10.0; // Move rectangle down 
  break; 
  case 'a': 
  rectPosX -= 10.0; // Move rectangle left 
  break; 
  case 'd': 
  rectPosX += 10.0; // Move rectangle right 
  break; 
  case 'r': 
  rotationAngle += 10.0; // Rotate clockwise 
  break; 
  case 'e': 
  rotationAngle -= 10.0; // Rotate counterclockwise 
  break; 
  case '+': 
  scaleX += 0.1; // Scale up 
  scaleY += 0.1; 
  break; 
  case '-': 
  14 
  scaleX -= 0.1; // Scale down 
  scaleY -= 0.1; 
  break; 
} 
glutPostRedisplay(); 
} 
int main(int argc, char** argv) { 
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(800, 600); 
glutInitWindowPosition(100, 100); 
glutCreateWindow("Basic Geometric Operations in OpenGL"); 
glutDisplayFunc(display); 
glutReshapeFunc(reshape); 
glutKeyboardFunc(keyboard); 
glClearColor(1.0, 1.0, 1.0, 1.0); // White background color 
glutMainLoop(); 
return 0; 
}
