#include "Header.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Mat FiltreMedian(Mat image)
{
	// Nos variables
	cv::Mat imageMed;

	/*filtre median sert à lisser l'image,
	ici prends un pixel et l'étend à 5 */
	medianBlur(image, imageMed, 5);
	return imageMed;
}

Mat FiltreGauss(Mat image)
{
	// Nos variables
	Mat imagegauss;
	/* filtre gaussien (entrée, sortie, taille_du_noyau soit floutage sur x et y,
	constante constante, constante non obligatoire) */
	GaussianBlur(image, imagegauss, Size(9, 9), 0, 0, BORDER_DEFAULT);
	return imagegauss;
}

Mat FiltreSobel(Mat image)
{
	// Nos Variables
	Mat imagegrey, grad, image_blur;

	// Les valeurs par deffaut
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	/* Filtre Gaussien -> GaussianBlur ( entrée, sortie, taille_du_noyau soit floutage
	sur x et y , constante , constante, constante non obligatoire ) */
	GaussianBlur(image, image_blur, Size(3, 3), 0, 0, BORDER_DEFAULT);

	// Change en 50 nuances de grey ( le 7 correspond au gris)
	cvtColor(image_blur, imagegrey, 7);

	// Calculs de gradients
		// Creer des matrices pour les gradients
	Mat grad_x, grad_y;

	/* Gradient X puis Y
	Sobel(entrée, sortie, profondeur, 1 si grad x 0 sinon, 1 si grad y 0 sinon,
	taille_noyau en n*n, valeur de base, valeur de base, cst non oblig) */
	Sobel(imagegrey, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	Sobel(imagegrey, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);

	// On convertie les résultats en CV_8U ( change le typage ) 
	convertScaleAbs(grad_x, grad_x);
	convertScaleAbs(grad_y, grad_y);

	/* On remet tt dans une seule matrice "grad" (
	addWeighted(1ere entrée de grad, constante de base, 2eme entree de grad,
	cst de base, const de base, sortie) ) */
	addWeighted(grad_x, 0.5, grad_y, 0.5, 0, grad);

	return grad;
}

Mat DilaEro()
{
	// Variables
	int choix, type;
	Mat element;

	//On a différents type d'érosion dispo donc on laisse le choix à l'utilisateur
	std::cout << "Souhaitez vous : 1 - Erosion en rectangle, 2 - Erosion en croix, 3 - Erosion en ellipse" << std::endl;
	std::cin >> choix;
	if (choix == 1)
	{
		type = MORPH_RECT;
	}
	else if (choix == 2)
	{
		type = MORPH_CROSS;
	}
	else if (choix == 3)
	{
		type = MORPH_ELLIPSE;
	}

	element = getStructuringElement(type, Size(2 * 3 + 1, 2 * 3 + 1), Point(3, 3));

	return element;
}

Mat FiltreDilatation(Mat image)
{
	Mat element = DilaEro();
	Mat erosion;

	//Calcul de l'érosion ( erode(entrée, erosion, kern de base 3*3) )
	dilate(image, erosion, element);

	return erosion;
}

Mat FiltreErosion(Mat image)
{
	Mat element = DilaEro();
	Mat dilatation;
	//Calcul de l'érosion ( erode(entrée, erosion, kern de base 3*3) )
	dilate(image, dilatation, element);

	return dilatation;
}

Mat FiltreCanny(Mat image)
{
	// Nos Variables
	Mat image_gris, image_blur, image_canny, image_noire;

	// Nos différentes variables de bases
	int seuil_canny = 3;

	// On creer une image de la même taille et type que image
	image_noire.create(image.size(), image.type());

	// Change image en nuances de gris
	cvtColor(image, image_gris, 7);

	// On floutte l'image avec un noyau de taille 3
	blur(image_gris, image_blur, Size(3, 3));

	/* On applique le filtre canny :
	Canny (image_entrée, imag_sortie,seuil_min, seuil_max =3*seuil_min)
	On utilise une taille de noyau de base = 3 */
	Canny(image_blur, image_canny, seuil_canny, 3 * seuil_canny);

	// On remplie la matrice de 0 -> l'image devient totallement noire
	image_noire = Scalar::all(0);

	// On copie le résultat du filtre dans notre image noire
	image.copyTo(image_noire, image_canny);

	return image_noire;
}

Mat FiltreSeuil(Mat image)
{
	// Nos variables
	int choix_seuil, valeur;
	Mat image_gris, image_seuil;

	// Convertie l'image en nuances de gris
	cvtColor(image, image_gris, 7);

	// On demande à l'utilisateur ce qu'il souhaite :
	do
	{
		std::cout << "Que voulez vous ?" << std::endl <<
			"0: Binary" << std::endl <<
			"1 : Binary Inverted" << std::endl <<
			"2 : Threshold Truncated" << std::endl <<
			"3 : Threshold to Zero" << std::endl <<
			"4 : Threshold to Zero Inverted" << std::endl;
		std::cin >> choix_seuil;
	} while (choix_seuil < 0 || choix_seuil > 4);

	// On demande à l'utilisateur la proportion voulue
	do
	{
		std::cout << "Quelle proportion voulez vous ?" <<
			"Entre 0 et 255, 127 conseillé" << std::endl;
		std::cin >> valeur;
	} while (valeur > 255 || valeur < 0);

	/* On utilise la fonction threshold
	threshold (entrée,sortie,valeur_utilisateur,valeur de base,type_choisi);*/
	threshold(image_gris, image_seuil, valeur, 255, choix_seuil);

	return image_seuil;
}

void affResult(Mat image, std::string windowName)
{
	//Affichage image
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, image);
	waitKey(0);
	destroyWindow(windowName);
}