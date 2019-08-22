import cv2
print cv2.__version__
print cv2.__file__

image = cv2.imread('images/bicycle.jpg')

fd = cv2.AKAZE_create()
(kps, descs) = fd.detectAndCompute(image, None)
print("keypoints: {}, descriptors: {}".format(len(kps), descs.shape))

# draw the keypoints and show the output image
cv2.drawKeypoints(image, kps, image, (0, 255, 0))
#cv2.imshow('output', image)
#cv2.waitKey(0)
cv2.imwrite('out/featureDetection.png', image)
