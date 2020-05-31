import cv2
import numpy as np
import time
import os
from flask import Flask
from flask import render_template
from flask_caching import Cache

cache = Cache(config={'CACHE_TYPE': 'null'})
app = Flask(__name__)
cache.init_app(app)
app.static_folder = 'static'


def dibujarContorno(contornos, color):
  for (i, c) in enumerate(contornos):
    M = cv2.moments(c)
    if (M["m00"]==0): M["m00"]==1
    cv2.drawContours(imagen, [c], 0, color, 2)
    cv2.putText(imagen, str(i+1), (10,10), 1, 2,(0,0,0),2)

amarilloBajo = np.array([20, 100, 20], np.uint8)
amarilloAlto = np.array([32, 255, 255], np.uint8)

violetaBajo = np.array([125,100,20], np.uint8)
violetaAlto = np.array([150,255,255], np.uint8)

verdeBajo = np.array([80, 100, 20], np.uint8)
verdeAlto = np.array([100, 255, 255], np.uint8)

rojoBajo1 = np.array([0, 100, 20], np.uint8)
rojoAlto1 = np.array([10, 255, 255], np.uint8)
rojoBajo2 = np.array([175, 100, 20], np.uint8)
rojoAlto2 = np.array([180, 255, 255], np.uint8)

video=cv2.VideoCapture(0)
check, frame = video.read()
cv2.waitKey(0)

imagen=frame

video.release()

imagenHSV = cv2.cvtColor(imagen, cv2.COLOR_BGR2HSV)

cv2.imwrite('static/conteo.png', imagenHSV)

#Detectando colores 

maskAmarillo = cv2.inRange(imagenHSV, amarilloBajo, amarilloAlto)
maskVioleta = cv2.inRange(imagenHSV, violetaBajo, violetaAlto)
maskVerde = cv2.inRange(imagenHSV, verdeBajo, verdeAlto)
maskRojo1 = cv2.inRange(imagenHSV, rojoBajo1, rojoAlto1)
maskRojo2 = cv2.inRange(imagenHSV, rojoBajo2, rojoAlto2)
maskRojo =  cv2.add(maskRojo1, maskRojo2)

#Encontrando contornos

contornosAmarillo = cv2.findContours(maskAmarillo, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
contornosVioleta = cv2.findContours(maskVioleta, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
contornosVerde = cv2.findContours(maskVerde, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
contornosRojo = cv2.findContours(maskRojo, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
dibujarContorno(contornosAmarillo, (0, 255,255))
dibujarContorno(contornosVioleta, (140, 40, 120))
dibujarContorno(contornosVerde, (0, 255, 0))
dibujarContorno(contornosRojo, (0, 0, 255))

#Imagen Resumen

imgResumen = 255 * np.ones((500,600,3), dtype = np.uint8)


cv2.circle(imgResumen, (30,70), 15, (140,40,120), -1)
cv2.circle(imgResumen, (30,110), 15, (0,255,0), -1)

if len(contornosVioleta)>235 or len(contornosVerde)>1:
   variable6= "bacteria detected" 
   variable67="It is recommended to disinfect again"
  
else:
    variable6= "No Danger"
    variable67="The product is in good condition"
    
totalCnts = len(contornosVioleta) + len(contornosVerde)
pr=totalCnts*100/totalCnts

promedioVirus = (len(contornosVerde) * 100)/totalCnts
promedioVirusHTML = promedioVirus

promedioDescontaminado = (len(contornosVioleta)*100)/totalCnts
promedioDescontaminadoHTML = promedioDescontaminado

cantidadVioleta = len(contornosVioleta)
cantidadVerde =len(contornosVerde)


cantidadTotal = cantidadVioleta + cantidadVerde

@app.route('/')
def index():
    return render_template('index.htm',  variable= promedioVirusHTML, variable2=promedioDescontaminadoHTML, variable3=cantidadVioleta, variable4=cantidadVerde, variable5=cantidadVioleta, variable6=variable6, recc=variable67)

if __name__ == '__main__':
    app.run(debug= True, port=8000)
    


cv2.waitKey(0)
cv2.destroyAllWindows()
