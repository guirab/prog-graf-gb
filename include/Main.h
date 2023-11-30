#include "Includes.h"
#include "Shader.h"

#define PI 3.14159265359
#define HALF_PI PI/2.0

vector<vec3*>* controlPoints = new vector<vec3*>();
vector<vec3*>* originalCurve = new vector<vec3*>();
vector<vec3*>* externalCurve = new vector<vec3*>();
vector<vec3*>* internalCurve = new vector<vec3*>();
vector<vec3*>* finalCurve = new vector<vec3*>();
vector<vec3*>* controlPointsColor = new vector<vec3*>();
vector<GLfloat>* controlPointsFloat = new vector<GLfloat>();
vector<GLfloat>* finalCurveFloat = new vector<GLfloat>();

int setup();
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void writeObjMtl();
void runBinds(GLuint vao, GLuint vbo, vector<GLfloat>* vector, float size);
float euclideanDistance(float xa, float ya, float xb, float yb);

int getZone(float x, float y);
void setCoordinatesByZone(double& xpos, double& ypos);
void convertCoordinates(double& x, double& y);

void calculateBSpline(vector<vec3*>* temp, vector<vec3*>* curvaCalculada, TXTWriter& TXTWriter);
vector<vec3*>* generateOriginalCurve(vector<vec3*>* points);
vector<vec3*>* generateSideCurve(vector<vec3*>* points, bool external);
vector<vec3*>* generateFinalCurve(vector<vec3*>* internalCurve, vector<vec3*>* externalCurve);
void generateNormals(vector<vec3*>* internalCurve, vector<vec3*>* externalCurve);
vector<GLfloat>* convertVectorToFloat(vector<vec3*>* points);
void generateCurve();

GLFWwindow* window;
GLint colorLoc;
GLuint vaoCurve, vboCurve;
GLuint vaoPoints, vboPoints;

const GLint WIDTH = 1200, HEIGHT = 900;
const float zIndexSensitivity = 0.01f;

int internalCurveSize = 0;
int externalCurveSize = 0;
int faces = 0;

int selectedIndex = -1;
static bool upPressed, downPressed;
