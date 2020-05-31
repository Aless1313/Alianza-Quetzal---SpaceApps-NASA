import cv2
import numpy as np
from flask import Flask
from flask import render_template

app = Flask(__name__)


def dibujarContorno(contornos, color):
  for (i, c) in enumerate(contornos):
    M = cv2.moments(c)
    if (M["m00"]==0): M["m00"]==1
    cv2.drawContours(imagen, [c], 0, color, 2)
    cv2.putText(imagen, str(i+1), (10,10), 1, 2,(0,0,0),2)



#naranja
naranjaBajo = np.array([11, 100, 20], np.uint8)
naranjaAlto = np.array([25, 255, 255], np.uint8)

#amarillo
naranjaBajo = np.array([26, 100, 20], np.uint8)
naranjaAlto = np.array([40, 255, 255], np.uint8)

#verde
verdeBajo = np.array([41, 100, 20], np.uint8)
verdeAlto = np.array([70, 255, 255], np.uint8)

#celeste
celesteBajo = np.array([71, 100, 20], np.uint8)
celesteAlto = np.array([100, 255, 255], np.uint8)

#azul
azulBajo = np.array([101, 100, 20], np.uint8)
azulAlto = np.array([124, 255, 255], np.uint8)

#violeta   
violetaBajo = np.array([125,100,20], np.uint8)
violetaAlto = np.array([140,255,255], np.uint8)

#rosa
rosaBajo = np.array([141,100,20], np.uint8)
rosaAlto = np.array([174,255,255], np.uint8)

#rojo
rojoBajo1 = np.array([0, 100, 20], np.uint8)
rojoAlto1 = np.array([10, 255, 255], np.uint8)
rojoBajo2 = np.array([175, 100, 20], np.uint8)
rojoAlto2 = np.array([180, 255, 255], np.uint8)

imagen = cv2.imread('agua.jpg')
#imagen = cv2.imread('3.jpg')

imagenHSV = cv2.cvtColor(imagen, cv2.COLOR_BGR2HSV)

#Detectando colores 

maskVioleta = cv2.inRange(imagenHSV, violetaBajo, violetaAlto)
maskVerde = cv2.inRange(imagenHSV, verdeBajo, verdeAlto)
maskNaranja = cv2.inRange(imagenHSV, verdeBajo, verdeAlto)
maskAmarillo = cv2.inRange(imagenHSV, verdeBajo, verdeAlto)
maskCeleste = cv2.inRange(imagenHSV, verdeBajo, verdeAlto)
maskAzul = cv2.inRange(imagenHSV, verdeBajo, verdeAlto)
maskRosa = cv2.inRange(imagenHSV, verdeBajo, verdeAlto)
maskRojo1 = cv2.inRange(imagenHSV, rojoBajo1, rojoAlto1)
maskRojo2 = cv2.inRange(imagenHSV, rojoBajo2, rojoAlto2)
maskRojo =  cv2.add(maskRojo1, maskRojo2)

#Encontrando contornos

contornosVioleta = cv2.findContours(maskVioleta, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
contornosVerde = cv2.findContours(maskVerde, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
contornosNaranja = cv2.findContours(maskNaranja, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
contornosAmarillo = cv2.findContours(maskAmarillo, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
contornosCeleste = cv2.findContours(maskCeleste, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
contornosAzul = cv2.findContours(maskAzul, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
contornosRosa = cv2.findContours(maskRosa, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
contornosRojo = cv2.findContours(maskRojo, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]

dibujarContorno(contornosVioleta, (140, 40, 120))
dibujarContorno(contornosVerde, (0, 255, 0))

dibujarContorno(contornosNaranja, (247, 153, 12))
dibujarContorno(contornosAmarillo, (241, 247, 40))

dibujarContorno(contornosCeleste, (40, 247, 241))
dibujarContorno(contornosAzul, (40, 40, 247))

dibujarContorno(contornosRosa, (247, 89, 179))
dibujarContorno(contornosRojo, (255, 0, 0))





#Imagen Resumen

imgResumen = 255 * np.ones((500,600,3), dtype = np.uint8)

#cv2.circle(imgResumen, (30,30), 15, (0,255,255), -1)
cv2.circle(imgResumen, (30,70), 15, (140,40,120), -1)
cv2.circle(imgResumen, (30,110), 15, (0,255,0), -1)

cv2.circle(imgResumen, (30,150), 15, (247,153,12), -1)
cv2.circle(imgResumen, (30,190), 15, (241,247,40), -1)

cv2.circle(imgResumen, (30,230), 15, (14,247,241), -1)
cv2.circle(imgResumen, (30,270), 15, (40,40,247), -1)

cv2.circle(imgResumen, (30,310), 15, (247,89,179), -1)
cv2.circle(imgResumen, (30,350), 15, (255,0,0), -1)


#cv2.circle(imgResumen, (30,150), 15, (0,0,255), -1)

#cv2.putText(imgResumen,str(len(contornosAmarillo)),(65,40), 1, 2,(0,0,0),2)
cv2.putText(imgResumen,"Areas violeta "+str(len(contornosVioleta)),(65,80), 1, 2,(0,0,0),2)
cv2.putText(imgResumen,"Areas verde "+str(len(contornosVerde)),(65,120), 1, 2,(0,0,0),2)

cv2.putText(imgResumen,"Areas naranja "+str(len(contornosNaranja)),(65,160), 1, 2,(0,0,0),2)
cv2.putText(imgResumen,"Areas amarilla "+str(len(contornosAmarillo)),(65,200), 1, 2,(0,0,0),2)

cv2.putText(imgResumen,"Areas celeste "+str(len(contornosCeleste)),(65,240), 1, 2,(0,0,0),2)
cv2.putText(imgResumen,"Areas azul "+str(len(contornosAzul)),(65,280), 1, 2,(0,0,0),2)

cv2.putText(imgResumen,"Areas rosa "+str(len(contornosRosa)),(65,320), 1, 2,(0,0,0),2)
cv2.putText(imgResumen,"Areas rojo "+str(len(contornosRojo)),(65,360), 1, 2,(0,0,0),2)

totalCnts = len(contornosVioleta) + len(contornosVerde) + len(contornosNaranja) + len(contornosAmarillo) + len(contornosCeleste) + len(contornosAzul) + len(contornosRosa) + len(contornosRojo)

if(totalCnts>1):
  notificacion = "Se ha detectado un objeto"
  cv2.putText(imgResumen,"Objetos detectados ",(55,450), 1, 2,(0,0,0),2)
else:
  notificacion_2 = "No se ha detectado ningun objeto"
cantidadVioleta = len(contornosVioleta)
cantidadVerde = len(contornosVioleta)
cantidadNaranja = len(contornosNaranja)
cantidadAmarillo = len(contornosAmarillo)
cantidadCeleste = len(contornosCeleste)
cantidadAzul = len(contornosAzul)
cantidadRosa = len(contornosRosa)
cantidadRojo = len(contornosRojo)


@app.route('/')
def index():
    return render_template('index.html', variable=cantidadVioleta, variable1=cantidadVerde, variable2=cantidadNaranja, variable3=cantidadAmarillo , variable4=cantidadCeleste, variable5=cantidadAzul , variable6=cantidadRosa, variable7=cantidadRojo, variable8="An object has been detected")

if __name__ == '__main__':
    app.run(debug= True, port=8001)


#cv2.putText(imgResumen,str(len(contornosRojo)),(65,160), 1, 2,(0,0,0),2)
#totalCnts = len(contornosAmarillo) + len(contornosVioleta) + len(contornosVerde) + len(contornosRojo)



cantidadVioleta = len(contornosVioleta)
cantidadVerde = len(contornosVerde)




#cv2.putText(imgResumen,"Total de areas detectadas: " + str(totalCnts),(55,200), 1, 2,(0,0,0),2)
#cv2.putText(imgResumen,"Total de areas detectadas: " + str(totalCnts),(55,400), 1, 2,(0,0,0),2)

cv2.imshow('Resumen', imgResumen)


cv2.imshow('Imagen', imagen)
cv2.imwrite('nuevaImagen2.jpg',imgResumen)
cv2.imwrite('static/images/objetoNuevo.jpg', imagen)
cv2.waitKey(0)
cv2.destroyAllWindows()


