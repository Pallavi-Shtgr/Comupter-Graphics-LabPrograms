import cv2 
# Read the image 
28 
image = cv2.imread('images.jpg') 
# Apply Gaussian blur 
blurred_image = cv2.GaussianBlur(image, (15, 15), 0) 
# Display the original and blurred images 
cv2.imshow('Original Image', image) 
cv2.imshow('Blurred Image', blurred_image) 
cv2.waitKey(0) 
cv2.destroyAllWindows()
