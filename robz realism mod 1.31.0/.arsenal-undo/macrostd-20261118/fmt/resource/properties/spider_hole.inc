
	
	{Simulation {Able 1}}
	
	{sensor
		{Visor "main"
			{vision "listen_around"}
			{bone "listen"}
		}
	{RecognizeTime 0.01}
	{InformRange 50 50}		;first - AI ;second - USER
	}
	
	{placer
		{place "lookout"
			{group "crew"}
			{linkbone "lookout"}
			{turnoff {shadow}}
			{visor "main"}
			{openForCrush}
		}
	}