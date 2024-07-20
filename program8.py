import cv2 
import numpy as np 
# Load the image 
image = cv2.imread('images.jpg') 
# Define rotation angle (in degrees), scaling factor, and translation values 
rotation_angle = 45 
scaling_factor = 1.5 
translation_x = 50 
translation_y = 50 
# Get image dimensions 
24 
height, width = image.shape[:2] 
# Define the rotation matrix 
rotation_matrix = cv2.getRotationMatrix2D((width / 2, height / 2), rotation_angle, 1) 
# Perform rotation 
rotated_image = cv2.warpAffine(image, rotation_matrix, (width, height)) 
# Perform scaling 
scaled_image = cv2.resize(image, None, fx=scaling_factor, fy=scaling_factor) 
# Perform translation 
translation_matrix = np.float32([[1, 0, translation_x], [0, 1, translation_y]]) 
translated_image = cv2.warpAffine(image, translation_matrix, (width, height)) 
# Display the original, rotated, scaled, and translated images 
cv2.imshow('Original Image', image) 
cv2.imshow('Rotated Image', rotated_image) 
cv2.imshow('Scaled Image', scaled_image) 
cv2.imshow('Translated Image', translated_image) 
cv2.waitKey(0) 
cv2.destroyAllWindows()
