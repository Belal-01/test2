#pragma once
#include <GL/glut.h>
#include <iostream>
#include <cstdlib> // ������ rand � srand
#include <ctime>   // ������ time
#include <random>

class TechnicalDivecesDrawer
{
public :
    void drawComputerMonitor(float x, float y, float z, float angleX, float angleY, float angleZ) {
        // ������� ������� ������ ��������
        float width = 50.0f;
        float height = 30.0f;
        float screenThickness = 1.0f; // ��� ������
        float baseWidth = 40.0f; // ����� �������
        float baseDepth = 15.0f; // ����� ��� �������
        float connectorHeight = 1.5f; // ����� ��� ������ ����� ��� �� ��� ������
        float buttonWidth = 3.0f; // ��� ����
        float buttonHeight = 1.0f; // ������ ����

        glPushMatrix();
        glTranslatef(x, y, z);

        // ����� �������
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // ����� ��� ������ X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // ����� ��� ������ Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // ����� ��� ������ Z

        // ��� ������ �� ����� ������
        glColor3f(0.0f, 0.0f, 0.0f); // ��� ������
        glBegin(GL_QUADS);
        // ����� ������
        glVertex3f(-width / 2, height, 0);
        glVertex3f(width / 2, height, 0);
        glVertex3f(width / 2, 0, 0);
        glVertex3f(-width / 2, 0, 0);

        // ����� ������ ������
        glVertex3f(-width / 2, height, screenThickness);
        glVertex3f(width / 2, height, screenThickness);
        glVertex3f(width / 2, 0, screenThickness);
        glVertex3f(-width / 2, 0, screenThickness);

        // ����� ������
        glVertex3f(-width / 2, height, 0);
        glVertex3f(-width / 2, height, screenThickness);
        glVertex3f(-width / 2, 0, screenThickness);
        glVertex3f(-width / 2, 0, 0);

        glVertex3f(width / 2, height, 0);
        glVertex3f(width / 2, height, screenThickness);
        glVertex3f(width / 2, 0, screenThickness);
        glVertex3f(width / 2, 0, 0);

        glVertex3f(-width / 2, height, screenThickness);
        glVertex3f(width / 2, height, screenThickness);
        glVertex3f(width / 2, height, 0);
        glVertex3f(-width / 2, height, 0);

        glVertex3f(-width / 2, 0, screenThickness);
        glVertex3f(width / 2, 0, screenThickness);
        glVertex3f(width / 2, 0, 0);
        glVertex3f(-width / 2, 0, 0);
        glEnd();

        // ��� �������
        glColor3f(0.2f, 0.2f, 0.2f); // ��� �������
        glBegin(GL_QUADS);
        glVertex3f(-baseWidth / 2, -connectorHeight, -baseDepth / 2);
        glVertex3f(baseWidth / 2, -connectorHeight, -baseDepth / 2);
        glVertex3f(baseWidth / 2, -connectorHeight, baseDepth / 2);
        glVertex3f(-baseWidth / 2, -connectorHeight, baseDepth / 2);
        glEnd();

        // ��� ������ (�������� �������) �� ��� ���
        glColor3f(0.4f, 0.4f, 0.4f); // ��� ������
        glBegin(GL_QUADS);
        // ��� �����
        glVertex3f(-baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, -baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, -baseDepth / 12);

        // ��� ����
        glVertex3f(-baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, baseDepth / 12);

        // ��� ����� (����)
        glVertex3f(-baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(-baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, -baseDepth / 12);

        // ��� ����� (����)
        glVertex3f(baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, -baseDepth / 12);
        glEnd();

        // ��� �� ������� (��� ���� ������ ���� ��� ������)
        glColor3f(1.0f, 0.0f, 0.0f); // ��� ���� ����
        glBegin(GL_QUADS);
        // ��� ���� ������ ����� ����
        glVertex3f(22, -connectorHeight + 2.0f, -0.1); // ����� ������ ����
        glVertex3f(25, -connectorHeight + 2.0f, -0.1); // ����� ������ ����
        glVertex3f(25, -connectorHeight + buttonHeight + 2.0f, -0.1); // ����� ������ ����
        glVertex3f(22, -connectorHeight + buttonHeight + 2.0f, -0.1); // ����� ������ ����
        glEnd();

        glPopMatrix();

    }
    static void drawScreen(float x, float y, float z, float angleX, float angleY, float angleZ) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f); // ����� ��� ������ X
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); // ����� ��� ������ Y
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); // ����� ��� ������ Z

        glColor3f(0.0f, 0.0f, 0.0f); // ��� ������
        glBegin(GL_QUADS);

        // ������
        glVertex3f(0, 0, 0);
        glVertex3f(60.0f, 0, 0);
        glVertex3f(60.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        glEnd();

        // ������
        glColor3f(0.2f, 0.2f, 0.2f);
        glBegin(GL_LINE_LOOP);

        glVertex3f(0, 0, 0);
        glVertex3f(60.0f, 0, 0);
        glVertex3f(60.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        glEnd();
        glPopMatrix();
    }
    void drawPS5(float x, float y, float z, float angleX, float angleY, float angleZ) {
        // ����� PS5
        float bodyWidth = 10.0f;
        float bodyHeight = 30.0f;
        float bodyDepth = 5.0f;
        float wingWidth = 12.0f;
        float wingHeight = 30.0f;
        float wingDepth = 0.5f;
        float wingOffset = 2.0f; // ������� ��� ����� ��������

        glPushMatrix();
        glTranslatef(x, y, z);

        // ����� �������
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // ����� ��� ������ X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // ����� ��� ������ Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // ����� ��� ������ Z

        // ��� ����� �������
        glColor3f(0.1f, 0.1f, 0.1f); // ��� ����� ������� (����)
        glBegin(GL_QUADS);
        // ��� �����
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        // ��� ����
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);

        // �������
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        // ������� ������
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);

        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glEnd();

        // ��� ������� ��������
        glColor3f(1.0f, 1.0f, 1.0f); // ��� ������� (����)
        glBegin(GL_QUADS);
        // ������ ������
        glVertex3f(5.1, 0, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(5.1, 0, 5);
        glVertex3f(5.1, wingHeight, 5);
        glVertex3f(5.1, wingHeight, -bodyDepth / 2 + wingDepth / 2);

        // ������ ������
        glVertex3f(-5.1, 0, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(-5.1, 0, 5);
        glVertex3f(-5.1, wingHeight, 5);
        glVertex3f(-5.1, wingHeight, -bodyDepth / 2 - wingDepth / 2);
        glEnd();
        glColor3f(0, 0, 0);
        glBegin(GL_LINES);
        glVertex3f(5.1, wingHeight / 2, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(5.1, wingHeight * 3 / 4, 5);
        glVertex3f(-5.1, wingHeight / 2, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(-5.1, wingHeight * 3 / 4, 5);
        glEnd();
        glPopMatrix();
    }
    void drawXbox(float x, float y, float z, float angleX, float angleY, float angleZ, int xboxf, int xboxb) {
        float bodyWidth = 24.0f;
        float bodyHeight = 12.0f;
        float bodyDepth = 20.0f;
        float buttonRadius = 2.0f; // ��� ������
        float logoRadius = 4.5f;
        glPushMatrix();
        glTranslatef(x, y, z);

        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        // ��� ��� Xbox
        glColor3f(0.5, 0.5, 0.5); // ��� ����� (����� ����)
        glBindTexture(GL_TEXTURE_2D, xboxf);
        glBegin(GL_QUADS);
        // ��� �����
        glTexCoord2f(0, 0);
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glTexCoord2f(1, 0);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glTexCoord2f(1, 1);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glTexCoord2f(0, 1);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        glEnd();

        glBindTexture(GL_TEXTURE_2D, xboxb);
        glBegin(GL_QUADS);

        // ��� ����
        glTexCoord2f(0, 0);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glTexCoord2f(1, 0);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glTexCoord2f(1, 1);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glTexCoord2f(0, 1);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);

        // �������
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        // ������� ������
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);

        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glEnd();



        glPopMatrix();
    }
    static void drawLaptop(float x, float y, float z, float angleX, float angleY, float angleZ) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // ����� ��� ������ X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // ����� ��� ������ Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // ����� ��� ������ Z

        glColor3f(0.3f, 0.3f, 0.3f); // ��� ��������
        glBegin(GL_QUADS);

        // ����� ��������
        glVertex3f(0, 0, 0);
        glVertex3f(50.0f, 0, 0);
        glVertex3f(50.0f, 30.0f, 0);
        glVertex3f(0, 30.0f, 0);

        // ������
        glVertex3f(0, 30.0f, 0);
        glVertex3f(50.0f, 30.0f, 0);
        glVertex3f(50.0f, 60.0f, -10.0f);
        glVertex3f(0, 60.0f, -10.0f);

        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f); // ��� ������ ����
        glBegin(GL_LINE_LOOP);

        glVertex3f(0.0f, 30.0f, 0.0f);


        glVertex3f(50.0f, 30.0f, 0.0f);


        glVertex3f(50.0f, 60.0f, -10.0f);


        glVertex3f(0.0f, 60.0f, -10.0f);

        glEnd();

        // ��� ��������
       // ��� ��������
        glColor3f(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);
        glBegin(GL_QUADS);

        // ��������
        for (int y = 0; y < 25; y += 5) {
            for (int x = 0; x < 50; x += 5) {
                glVertex3f(x + 2, y + 2, -0.1f);             // ������� ������� ������
                glVertex3f(x + 4, y + 2, -0.1f);         // ������� ������� ������
                glVertex3f(x + 4, y + 4, -0.1f);     // ������� ������ ������
                glVertex3f(x + 2, y + 4, -0.1f);         // ������� ������ ������
            }
        }

        glEnd();
        glColor3f(0.1, 0.1, 0.1);
        glBegin(GL_LINES);
        for (float y = 25; y < 29; y += 0.4) {
            glVertex3f(5, y, 0.1);
            glVertex3f(45, y, 0.1);
        }


        glEnd();
        glPopMatrix();
    }
    void drawKeyboard(float x, float y, float z, float angleX, float angleY, float angleZ) {
        // ����� ��������
        float keyboardWidth = 60.0f;
        float keyboardHeight = 15.0f;
        float keyboardDepth = 2.0f; // ��� ��������
        float keyHeight = 1.0f; // ������ �������
        float cableThickness = 0.5f;
        float cableLength = 20.0f;

        glPushMatrix();
        glTranslatef(x, y, z);

        // ����� �������
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // ����� ��� ������ X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // ����� ��� ������ Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // ����� ��� ������ Z

        // ��� ��������
        glColor3f(0.2f, 0.2f, 0.2f); // ��� ��������
        glBegin(GL_QUADS);
        // ��� �������� ������
        glVertex3f(-keyboardWidth / 2, 0, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, keyboardHeight / 2);

        // ������� ������ ������
        glVertex3f(-keyboardWidth / 2, -keyboardDepth, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, -keyboardDepth, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, -keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, -keyboardHeight / 2);

        glVertex3f(-keyboardWidth / 2, -keyboardDepth, keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, -keyboardDepth, keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, keyboardHeight / 2);

        glVertex3f(-keyboardWidth / 2, -keyboardDepth, -keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, -keyboardDepth, keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, -keyboardHeight / 2);

        glVertex3f(keyboardWidth / 2, -keyboardDepth, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, -keyboardDepth, keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, -keyboardHeight / 2);
        glEnd();

        // ��� �������
        glColor3f(0.8f, 0.8f, 0.8f); // ��� �������
        float keyWidth = 4.0f;
        float keyDepth = 4.0f;
        float spacing = 1.0f; // ������� ��� �������

        for (float row = -keyboardHeight / 2 + spacing; row < keyboardHeight / 2 - spacing; row += keyDepth + spacing) {
            for (float col = -keyboardWidth / 2 + spacing; col < keyboardWidth / 2 - spacing; col += keyWidth + spacing) {
                glBegin(GL_QUADS);
                glVertex3f(col, keyHeight, row);
                glVertex3f(col + keyWidth, keyHeight, row);
                glVertex3f(col + keyWidth, keyHeight, row + keyDepth);
                glVertex3f(col, keyHeight, row + keyDepth);

                glVertex3f(col, keyHeight, row);
                glVertex3f(col + keyWidth, keyHeight, row);
                glVertex3f(col + keyWidth, 0, row);
                glVertex3f(col, 0, row);

                glVertex3f(col, keyHeight, row + keyDepth);
                glVertex3f(col + keyWidth, keyHeight, row + keyDepth);
                glVertex3f(col + keyWidth, 0, row + keyDepth);
                glVertex3f(col, 0, row + keyDepth);

                glVertex3f(col, keyHeight, row);
                glVertex3f(col, keyHeight, row + keyDepth);
                glVertex3f(col, 0, row + keyDepth);
                glVertex3f(col, 0, row);

                glVertex3f(col + keyWidth, keyHeight, row);
                glVertex3f(col + keyWidth, keyHeight, row + keyDepth);
                glVertex3f(col + keyWidth, 0, row + keyDepth);
                glVertex3f(col + keyWidth, 0, row);
                glEnd();
            }
        }

        // ��� ������
        glColor3f(0.0f, 0.0f, 0.0f); // ��� ������
        glBegin(GL_QUADS);
        glVertex3f(-cableThickness / 2, 0, keyboardHeight / 2);
        glVertex3f(cableThickness / 2, 0, keyboardHeight / 2);
        glVertex3f(cableThickness / 2, -cableThickness, keyboardHeight / 2 + cableLength);
        glVertex3f(-cableThickness / 2, -cableThickness, keyboardHeight / 2 + cableLength);
        glEnd();

        glPopMatrix();
    }
    static void drawPhone(float x, float y, float z, float angleX, float angleY, float angleZ, float r, float g, float b) {
        float thickness = 1.0f; // ��� ������

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // ����� ��� ������ X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // ����� ��� ������ Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // ����� ��� ������ Z

        // ��� ������ ������� ������
        glColor3f(r, g, b); // ��� ������
        glBegin(GL_QUADS);

        // ��� �����
        glVertex3f(0, 0, 0);
        glVertex3f(20.0f, 0, 0);
        glVertex3f(20.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        // ��� ����
        glVertex3f(0, 0, -thickness);
        glVertex3f(20.0f, 0, -thickness);
        glVertex3f(20.0f, 40.0f, -thickness);
        glVertex3f(0, 40.0f, -thickness);

        // ������ ��������
        glVertex3f(0, 0, 0);
        glVertex3f(0, 40.0f, 0);
        glVertex3f(0, 40.0f, -thickness);
        glVertex3f(0, 0, -thickness);

        glVertex3f(20.0f, 0, 0);
        glVertex3f(20.0f, 40.0f, 0);
        glVertex3f(20.0f, 40.0f, -thickness);
        glVertex3f(20.0f, 0, -thickness);

        glVertex3f(0, 0, 0);
        glVertex3f(20.0f, 0, 0);
        glVertex3f(20.0f, 0, -thickness);
        glVertex3f(0, 0, -thickness);

        glVertex3f(0, 40.0f, 0);
        glVertex3f(20.0f, 40.0f, 0);
        glVertex3f(20.0f, 40.0f, -thickness);
        glVertex3f(0, 40.0f, -thickness);

        glEnd();

        // ��� ������
        glColor3f(0.0f, 0.0f, 0.0f); // ��� ������
        glBegin(GL_QUADS);

        glVertex3f(2.0f, 2.0f, 0.01f);
        glVertex3f(18.0f, 2.0f, 0.01f);
        glVertex3f(18.0f, 38.0f, 0.01f);
        glVertex3f(2.0f, 38.0f, 0.01f);

        glEnd();

        // ��� ���� �������
        glColor3f(0.5f, 0.5f, 0.5f); // ��� ����
        glBegin(GL_QUADS);

        glVertex3f(8.0f, 0.5f, 0.02f);
        glVertex3f(12.0f, 0.5f, 0.02f);
        glVertex3f(12.0f, 2.0f, 0.02f);
        glVertex3f(8.0f, 2.0f, 0.02f);

        glEnd();

        // ��� ������� ��������
        glColor3f(0.4f, 0.4f, 0.4f); // ��� ������� ��������
        glBegin(GL_QUADS);

        // �� ������ ��� ������ ������
        glVertex3f(20.0f, 30.0f, -0.2f);  // ���� ���� ������
        glVertex3f(20.5f, 30.0f, -0.2f);
        glVertex3f(20.5f, 32.0f, -0.2f);
        glVertex3f(20.0f, 32.0f, -0.2f);

        // ����� ����� ��� ������ ������
        glVertex3f(-0.5f, 30.0f, -0.2f);  // ���� ���� ������
        glVertex3f(-0.0f, 30.0f, -0.2f);
        glVertex3f(-0.0f, 32.0f, -0.2f);
        glVertex3f(-0.5f, 32.0f, -0.2f);

        glVertex3f(-0.5f, 27.0f, -0.2f);
        glVertex3f(-0.0f, 27.0f, -0.2f);
        glVertex3f(-0.0f, 29.0f, -0.2f);
        glVertex3f(-0.5f, 29.0f, -0.2f);

        glEnd();

        glPopMatrix();
    }
    static void drawTablet(float x, float y, float z, float angleX, float angleY, float angleZ, float r, float g, float b) {
        float thickness = 1.0f; // ��� ������

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // ����� ��� ������ X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // ����� ��� ������ Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // ����� ��� ������ Z

        // ��� ������ ������� ������
        glColor3f(r, g, b); // ��� ������
        glBegin(GL_QUADS);

        // ��� �����
        glVertex3f(0, 0, 0);
        glVertex3f(30.0f, 0, 0);
        glVertex3f(30.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        // ��� ����
        glVertex3f(0, 0, -thickness);
        glVertex3f(30.0f, 0, -thickness);
        glVertex3f(30.0f, 40.0f, -thickness);
        glVertex3f(0, 40.0f, -thickness);

        // ������ ��������
        glVertex3f(0, 0, 0);
        glVertex3f(0, 40.0f, 0);
        glVertex3f(0, 40.0f, -thickness);
        glVertex3f(0, 0, -thickness);

        glVertex3f(30.0f, 0, 0);
        glVertex3f(30.0f, 40.0f, 0);
        glVertex3f(30.0f, 40.0f, -thickness);
        glVertex3f(30.0f, 0, -thickness);

        glVertex3f(0, 0, 0);
        glVertex3f(30.0f, 0, 0);
        glVertex3f(30.0f, 0, -thickness);
        glVertex3f(0, 0, -thickness);

        glVertex3f(0, 40.0f, 0);
        glVertex3f(30.0f, 40.0f, 0);
        glVertex3f(30.0f, 40.0f, -thickness);
        glVertex3f(0, 40.0f, -thickness);

        glEnd();

        // ��� ������
        glColor3f(0.0f, 0.0f, 0.0f); // ��� ������
        glBegin(GL_QUADS);

        glVertex3f(2.0f, 2.0f, 0.01f);
        glVertex3f(28.0f, 2.0f, 0.01f);
        glVertex3f(28.0f, 38.0f, 0.01f);
        glVertex3f(2.0f, 38.0f, 0.01f);

        glEnd();

        // ��� ���� �������
        glColor3f(0.5f, 0.5f, 0.5f); // ��� ����
        glBegin(GL_QUADS);

        glVertex3f(13.0f, 0.5f, 0.02f);
        glVertex3f(17, 0.5f, 0.02f);
        glVertex3f(17.0f, 2.0f, 0.02f);
        glVertex3f(13.0f, 2.0f, 0.02f);

        glEnd();

        // ��� ������� ��������
        glColor3f(0.4f, 0.4f, 0.4f); // ��� ������� ��������
        glBegin(GL_QUADS);

        // �� ������ ��� ������ ������
        glVertex3f(30.0f, 30.0f, -0.2f);  // ���� ���� ������
        glVertex3f(30.5f, 30.0f, -0.2f);
        glVertex3f(30.5f, 32.0f, -0.2f);
        glVertex3f(30.0f, 32.0f, -0.2f);

        // ����� ����� ��� ������ ������
        glVertex3f(-0.5f, 30.0f, -0.2f);  // ���� ���� ������
        glVertex3f(-0.0f, 30.0f, -0.2f);
        glVertex3f(-0.0f, 32.0f, -0.2f);
        glVertex3f(-0.5f, 32.0f, -0.2f);

        glVertex3f(-0.5f, 27.0f, -0.2f);
        glVertex3f(-0.0f, 27.0f, -0.2f);
        glVertex3f(-0.0f, 29.0f, -0.2f);
        glVertex3f(-0.5f, 29.0f, -0.2f);

        glEnd();

        glPopMatrix();
    }
    static void drawSpeakerFrame(float x, float y, float z, float angleX, float angleY, float angleZ, int  speaker) {
        float speakerWidth = 20.0f;   // ��� �������
        float speakerHeight = 60.0f;  // ������ �������
        float speakerDepth = 20.0f;   // ��� �������

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        // ��� ��������
        glBindTexture(GL_TEXTURE_2D, speaker);

        // ����� ����� ��������
     

        // ��� ������ ������ ���� ������� (������ ��������)
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);

        // ����� ��������
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glEnd();
        glColor3f(0.2, 0.2, 0.2);
        glBegin(GL_QUADS);
        // ����� �������
        glVertex3f(-speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
    glVertex3f(speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
         glVertex3f(speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);
         glVertex3f(-speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);

        // ����� ������
        glVertex3f(-speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);
       glVertex3f(speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
         glVertex3f(-speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);

        // ����� ������
         glVertex3f(-speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
         glVertex3f(speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
         glVertex3f(-speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);

        // ����� ������
     glVertex3f(speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
         glVertex3f(speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
       glVertex3f(speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glVertex3f(speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);

        // ����� ������
         glVertex3f(-speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(-speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glVertex3f(-speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
         glVertex3f(-speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);

        glEnd();

        glPopMatrix();

       
    }
    static void drawComputerCase(float x, float y, float z, float angleX, float angleY, float angleZ,int pcf,int pcb,int pcs) {
        float caseWidth = 60.0f;   // ��� ����� (���� ���)
        float caseHeight = 40; // ������ �����
        float caseDepth = 20.0f;   // ��� ����� (���� �� �����)

        glPushMatrix();
        glTranslatef(x, y+ caseHeight / 2, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
        glColor3f(0, 0, 0);
        // ��� ������ ����� ����� (������ ��������)
        glBegin(GL_QUADS);

        // ����� �������� (��� ���� �� �����)
        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2);   // ���� ������
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2);    // ���� ������
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2);     // ���� ������
        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2);    // ���� ������

      
        // ����� ������
        glVertex3f(-caseWidth / 2, caseHeight / 2, -caseDepth / 2);   // ���� ������
        glVertex3f(caseWidth / 2, caseHeight / 2, -caseDepth / 2);    // ���� ������
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2);     // ���� ������
        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2);    // ���� ������

        // ����� ������
        glVertex3f(-caseWidth / 2, -caseHeight / 2, -caseDepth / 2);  // ���� ������
        glVertex3f(caseWidth / 2, -caseHeight / 2, -caseDepth / 2);   // ���� ������
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2);    // ���� ������
        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2);   // ���� ������
        glEnd();

      
        glColor3f(0.5, 0.5, 0.5);

        glBindTexture(GL_TEXTURE_2D, pcs);
        glBegin(GL_QUADS);
        // ����� ������� (��� ������� ��� �������� ���� �� ������� �������)
        glTexCoord2f(1, 0);
        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2 -5);  // ���� ������
        glTexCoord2f(0, 0);
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2-5);   // ���� ������
        glTexCoord2f(0, 1);
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2-5);    // ���� ������
        glTexCoord2f(1, 1);
        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2-5);   // ���� ������
        glEnd();
        glColor3f(0.5, 0.5, 0.5);

        glBindTexture(GL_TEXTURE_2D, pcb);
        glBegin(GL_QUADS);
        // ����� ������
        glTexCoord2f(1, 0);
        glVertex3f(caseWidth / 2, -caseHeight / 2, -caseDepth / 2);   // ���� ������
        glTexCoord2f(0, 0);
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2);    // ���� ������

        glTexCoord2f(0, 1);
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2);     // ���� ������
        glTexCoord2f(1, 1);
        glVertex3f(caseWidth / 2, caseHeight / 2, -caseDepth / 2);    // ���� ������
        glEnd();
        glColor3f(0.5, 0.5, 0.5);

        glBindTexture(GL_TEXTURE_2D, pcf);
        glBegin(GL_QUADS);
        // ����� ������
        
        glTexCoord2f(1, 0);
        glVertex3f(-caseWidth / 2, -caseHeight / 2, -caseDepth / 2);  // ���� ������
        glTexCoord2f(0, 0);
       
        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2);   // ���� ������
        glTexCoord2f(0, 1);
       

        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2);    // ���� ������
         glTexCoord2f(1, 1);
      
        glVertex3f(-caseWidth / 2, caseHeight / 2, -caseDepth / 2);   // ���� ������

        glEnd();

        glPopMatrix();
    }

};
