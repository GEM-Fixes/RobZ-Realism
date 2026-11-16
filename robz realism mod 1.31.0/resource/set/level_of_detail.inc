;{levelofdetail
	(define "scale"
		(* 1.0 %d)
	)
	(mod "mp"
		(define "scale"
			(* 1.0 %d)
		)
	)
	(mod "coop"
		(define "scale"
			(* 0.70 %d)
		)
	)
	{"human"
		{distance ("scale" d(200))


			; LOD1
		}
		{distance ("scale" d(500))
			{NoGetShadow}
			; LOD2
		}
		{distance ("scale" d(1500))
			; LOD3
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(2000))
		}
		{distance ("scale" d(6000))
			("off")
		}
	}
	{"stuff_weapon"
		{distance ("scale" d(200))
			; LOD1
		}
		{distance ("scale" d(500))
			; LOD2


			{NoGetShadow}
		}
		{distance ("scale" d(600))
			; LOD3
			{NoCastShadow}
		}
		{distance ("scale" d(800))
			{NoFog}
		}
		{distance ("scale" d(1000))
			("off")
		}
	}
	{"vehicle_civilian"
		{distance ("scale" d(200))
			; LOD1
		}
		{distance ("scale" d(500))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(3000))
			("off")
		}
	}
	{"vehicle_small"
		{distance ("scale" d(200))
			; LOD1
		}
		{distance ("scale" d(500))


			{NoGetShadow}
			{NoFog}
		}
		{distance ("scale" d(1000))
			{NoCastShadow}
			{NoFog}
		}
		{distance ("scale" d(6000))
			("off")
		}
	}
	{"vehicle_big"
		{distance ("scale" d(200))
			; LOD1
		}
		{distance ("scale" d(500))


			{NoGetShadow}
		}
		{distance ("scale" d(1000))
			{NoCastShadow}
			{NoFog}
		}
		{distance ("scale" d(6000))
			("off")
		}
	}
	{"stuff_small"
		{distance ("scale" d(200))
			; LOD1


		}
		{distance ("scale" d(500))
			; LOD2
			{NoGetShadow}
		}
		{distance ("scale" d(600))
			; LOD3
			{NoCastShadow}
		}
		{distance ("scale" d(800))
			{NoFog}
		}
		{distance ("scale" d(2500))
			("off")
		}
	}
	{"part_small"
		{distance ("scale" d(200))


			; LOD1
		}
		{distance ("scale" d(500))
			; LOD2
			{NoGetShadow}
		}
		{distance ("scale" d(1000))
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(2500))
			("off")
		}
	}
	{"part_big"
		{distance ("scale" d(200))
			; LOD1


		}
		{distance ("scale" d(500))
			; LOD2
			{NoGetShadow}
		}
		{distance ("scale" d(1000))
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(3000))
			("off")
		}
	}
	{"decor_tiny"
		{distance ("scale" d(200))
			; LOD1


		}
		{distance ("scale" d(500))
			; LOD2
			{NoGetShadow}
		}
		{distance ("scale" d(1000))
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(2500))
			("off")
		}
	}
	{"decor_small"
		{distance ("scale" d(200))
			; LOD1


		}
		{distance ("scale" d(500))
			; LOD2
		}
		{distance ("scale" d(1000))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(6000))
			("off")
		}
	}
	{"decor_medium"
		{distance ("scale" d(200))
			; LOD1


		}
		{distance ("scale" d(500))
			; LOD2
			{NoGetShadow}
		}
		{distance ("scale" d(1000))
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(6000))
			("off")
		}
	}
	{"decor_big"
		{distance ("scale" d(200))
			; LOD1


		}
		{distance ("scale" d(500))
			; LOD2
			{NoGetShadow}
		}
		{distance ("scale" d(1000))
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(6000))
			("off")
		}
	}
	{"decor_tree"
		{distance ("scale" d(200))
			; LOD1


		}
		{distance ("scale" d(500))
			; LOD2
			{NoGetShadow}
		}
		{distance ("scale" d(1000))
			; LOD3
		}
		{distance ("scale" d(2000))
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(6000))
			; LOD5
			("off")
		}
	}
	{GrassDistance ("scale" d(2000))}
	{GrassFadeDepth ("scale" d(1000))}
;}