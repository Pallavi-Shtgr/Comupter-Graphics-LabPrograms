import cv2 
# Read the image in grayscale 
29 
image = cv2.imread('images.jpg', cv2.IMREAD_GRAYSCALE) 
# Apply binary thresholding 
ret, thresh = cv2.threshold(image, 127, 255, 0) 
# Find contours 
contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, 
cv2.CHAIN_APPROX_SIMPLE) 
# Draw contours on a blank image 
contour_image = cv2.cvtColor(image, cv2.COLOR_GRAY2BGR) 
cv2.drawContours(contour_image, contours, -1, (0, 255, 0), 2) 
# Display the original and contoured images 
cv2.imshow('Original Image', image) 
cv2.imshow('Contoured Image', contour_image) 
cv2.waitKey(0) 
cv2.destroyAllWindows()
