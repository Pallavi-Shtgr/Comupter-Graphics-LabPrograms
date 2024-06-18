Develop a program to demonstrate basic geometric Operationson 3D Objectin C++ using GLUT
 #include <GL/glut.h>
 #include <iostream>
 GLfloat cubeSize = 1.0f;
 GLfloat cubePosX = 0.0f, cubePosY = 0.0f, cubePosZ = -5.0f;
 GLfloat anglex = 0.0f, angley = 0.0f;
 GLfloat scale = 1.0f;
  void drawCube() { 
  glPushMatrix();
  glTranslatef (cubePosX, cubePosy, cubePosZ);
  glRotatef (anglex, 1.0f, 0.0f, 0.0f);
  lRotatef (angley, 0.0f, 1.0f, 0.0f);
  glScalef(scale, scale, scale);
  glBegin(GL_QUADS);
  glColor3f(1.0f, 0.0f, 0.0f);
  
  glVertex3f(-cubeSize, cubeSize, cubeSize);
  
  glVertex3f(cubeSize, cubeSize, cubeSize);
  
  glVertex3f(cubeSize, cubesize, cubeSize);
  
  glVertex3f(-cubeSize, cubeSize, cubeSize);
