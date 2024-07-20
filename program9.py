import cv2 
import numpy as np 
# Read the image 
image = cv2.imread('images.jpg', cv2.IMREAD_GRAYSCALE) 
# Apply Sobel filter for edge detection 
sobel_x = cv2.Sobel(image, cv2.CV_64F, 1, 0, ksize=3) 
sobel_y = cv2.Sobel(image, cv2.CV_64F, 0, 1, ksize=3) 
sobel_edge = cv2.magnitude(sobel_x, sobel_y) 
# Apply Laplacian filter for edge detection 
laplacian_edge = cv2.Laplacian(image, cv2.CV_64F) 
# Apply Gaussian blur for texture extraction 
gaussian_blur = cv2.GaussianBlur(image, (5, 5), 0) 
# Display the original image and extracted features 
cv2.imshow('Original Image', image) 
cv2.imshow('Sobel Edge Detection', np.uint8(sobel_edge)) 
cv2.imshow('Laplacian Edge Detection', np.uint8(laplacian_edge)) 
cv2.imshow('Gaussian Blurred Image', gaussian_blur) 
cv2.waitKey(0) 
cv2.destroyAllWindows()
