#ifndef _CAMERA_H_
#define _CAMERA_H_

// Defines several possible options for camera movement.
enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Camera
{
public:
	Camera();
	~Camera();

	void ProcessKeyboard(CameraMovement direction, float deltaTime);

private:

};
#endif // !_CAMERA_H_
