#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
using namespace std;

int main(void){
    GLFWwindow* window;

    //GLFW 라이브러리 초기화
    if(!glfwInit())
	return -1;

    //OpenGL context가 있는 창 만들기
    window = glfwCreateWindow(500, 500, "Hello OpenGL", NULL, NULL);
    if(!window){
	glfwTerminate();
	return -1;
    }

    //current OpenGL context 만들기
    glfwMakeContextCurrent(window);

    //GLEW 라이브러리 초기화
    if(glewInit() != GLEW_OK)
	cout << "GLEW Init Error!" << endl;

    //OpenGL 버전 프린트
    cout << glGetString(GL_VERSION) << endl;

    while(!glfwWindowShouldClose(window)){

	glClearColor(0.5, 0.5, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glfwSwapBuffers(window);

	glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
