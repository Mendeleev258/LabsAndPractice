﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2Construction.Model
{
    public class Bricklayer : Staff
    {
        public Bricklayer(int x, int y, int id) : base(x, y, id)
        {
        }

        public Bricklayer(Point point, int id) : base(point, id) { }
        public override MaterialType WorkWith => MaterialType.Brick;
    }
}
