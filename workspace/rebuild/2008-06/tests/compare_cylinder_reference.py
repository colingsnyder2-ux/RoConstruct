"""Compare the authored green cylinder silhouette in two rendered captures."""
import json
import sys

import cv2
import numpy as np
from PIL import Image


def mask(path):
    pixels = np.asarray(Image.open(path).convert('RGB')).astype(int)
    image = ((pixels[:, :, 1] > pixels[:, :, 0] * 1.3) &
             (pixels[:, :, 1] > pixels[:, :, 2] * 1.05) &
             (pixels[:, :, 1] < 110) & (pixels[:, :, 1] > 15)).astype('uint8')
    contours, _ = cv2.findContours(image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contour = max(contours, key=cv2.contourArea)
    image[:] = 0
    cv2.drawContours(image, [contour], -1, 1, -1)
    y, x = np.where(image)
    image = image[y.min():y.max()+1, x.min():x.max()+1]
    return np.asarray(Image.fromarray(image).resize((256, 256), Image.Resampling.NEAREST)) > 0


original, rebuilt = map(mask, sys.argv[1:3])
iou = float((original & rebuilt).sum() / (original | rebuilt).sum())
print(json.dumps({'normalized_silhouette_iou': iou, 'gate': 0.98, 'pass': iou >= 0.98}, indent=2))
if iou < 0.98:
    raise SystemExit(1)
